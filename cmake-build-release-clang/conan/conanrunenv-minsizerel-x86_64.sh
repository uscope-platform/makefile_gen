script_folder="/home/fils/git/makefilegen_v2/cmake-build-release-clang/conan"
echo "echo Restoring environment" > "$script_folder/deactivate_conanrunenv-minsizerel-x86_64.sh"
for v in OPENSSL_MODULES
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanrunenv-minsizerel-x86_64.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanrunenv-minsizerel-x86_64.sh"
    fi
done


export OPENSSL_MODULES="/home/fils/.conan2/p/b/opens98a9ccc86bac4/p/lib/ossl-modules"