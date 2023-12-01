#!/usr/bin/env sh
export CONAN_OLD_LD_LIBRARY_PATH="$LD_LIBRARY_PATH"
export CONAN_OLD_PATH="$PATH"

while read -r line; do
    LINE="$(eval echo $line)";
    export "$LINE";
done < "/home/tri/Downloads/HTTPClient clone/build/environment_run.sh.env"

export CONAN_OLD_PS1="$PS1"
export PS1="(conanrunenv) $PS1"