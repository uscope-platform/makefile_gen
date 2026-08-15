//  Copyright 2026 Filippo Savi
//  Author: Filippo Savi <filssavi@gmail.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ANANKE_CRASH_CONTEXT_HPP
#define ANANKE_CRASH_CONTEXT_HPP

#include <string>
#include <csignal>
#include <unistd.h>

struct crash_context {
    void set(std::string ent, std::string f) {
        entity = std::move(ent);
        file = std::move(f);
    }

    std::string entity;
    std::string file;
    std::string parameter;
};
inline thread_local crash_context crash_ctx;

namespace {
    // Write the whole buffer, handling short writes. Only async-signal-safe
    // operations are used here because this runs inside a signal handler.
    void write_all(int fd, const void *buf, size_t n) {
        const char *p = static_cast<const char*>(buf);
        while (n > 0) {
            ssize_t written = write(fd, p, n);
            if (written <= 0) return;
            p += written;
            n -= static_cast<size_t>(written);
        }
    }
}

inline void install_crash_handler() {
    struct sigaction sa = {};
    sa.sa_handler = [](int) {
        write_all(STDERR_FILENO, "\nCRASH while processing: ", sizeof("\nCRASH while processing: ") - 1);
        if (!crash_ctx.entity.empty())
            write_all(STDERR_FILENO, crash_ctx.entity.data(), crash_ctx.entity.size());
        write_all(STDERR_FILENO, " (", sizeof(" (") - 1);
        if (!crash_ctx.file.empty())
            write_all(STDERR_FILENO, crash_ctx.file.data(), crash_ctx.file.size());
        write_all(STDERR_FILENO, ")", sizeof(")") - 1);
        if (!crash_ctx.parameter.empty()) {
            write_all(STDERR_FILENO, " parameter: ", sizeof(" parameter: ") - 1);
            write_all(STDERR_FILENO, crash_ctx.parameter.data(), crash_ctx.parameter.size());
        }
        write_all(STDERR_FILENO, "\n", sizeof("\n") - 1);
        _exit(1);
    };
    sigaction(SIGSEGV, &sa, nullptr);
    sigaction(SIGABRT, &sa, nullptr);
    sigaction(SIGBUS, &sa, nullptr);
    sigaction(SIGFPE, &sa, nullptr);
}

#endif
