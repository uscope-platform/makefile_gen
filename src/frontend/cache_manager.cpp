//
// Created by fils on 10/06/2021.
//

#include "frontend/cache_manager.h"

cache_manager::cache_manager(std::shared_ptr<settings_store> settings) {
    store = std::move(settings);
    load_cache_backend();
}

void cache_manager::add_file(std::filesystem::path &file) {
    cache[file.string()] = hash_file(file);
}

bool cache_manager::is_changed(std::filesystem::path &file) {
    std::string current_digest = hash_file(file);
    return current_digest != cache[file.string()];
}

std::string cache_manager::hash_file(std::filesystem::path &file) {
    unsigned int size;
    std::vector<std::string> file_chunks;

    std::ifstream infile(file);

    std::vector<char> buffer (SHA256_DIGEST_LENGTH,0);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    while(!infile.eof()) {
        infile.read(buffer.data(), buffer.size());
        std::string chunk(buffer.begin(), buffer.end());
        SHA256_Update(&sha256, chunk.c_str(), chunk.size());
    }
    SHA256_Final(hash, &sha256);
    char * raw_str = OPENSSL_buf2hexstr(hash, SHA256_DIGEST_LENGTH);
    std::string hash_digest(raw_str);
    OPENSSL_free(raw_str);

    return hash_digest;
}

bool cache_manager::is_cached(std::filesystem::path &file) {
    return cache.count(file.string())>0;
}

void cache_manager::load_cache_backend() {
    std::istringstream cache_stream(store->get_setting("cache_dump"));

    std::string cache_line;
    while (std::getline(cache_stream, cache_line,';')){
        std::istringstream ss(cache_line);
        std::string tokens[2];
        int i = 0;
        while(std::getline(ss, tokens[i], '>')) {
            i++;
        }
        cache[tokens[0]] = tokens[1];
    }
}

void cache_manager::store_cache_backend() {
    std::ostringstream cache_str;
    for(const auto& item: cache){
        cache_str << item.first << ">" << item.second << ";";
    }
    store->set_setting("cache_dump", cache_str.str());
}

cache_manager::~cache_manager() {
    store_cache_backend();
}
