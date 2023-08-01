script_folder="/home/fils/git/makefilegen_v2/cmake-build-release-clang/conan"
echo "echo Restoring environment" > "$script_folder/deactivate_conanbuildenv-minsizerel-x86_64.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanbuildenv-minsizerel-x86_64.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanbuildenv-minsizerel-x86_64.sh"
    fi
done

