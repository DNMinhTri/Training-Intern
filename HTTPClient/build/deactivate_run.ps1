$function:prompt = $function:_old_conan_conanrunenv_prompt
remove-item function:_old_conan_conanrunenv_prompt


$env:LD_LIBRARY_PATH=$env:CONAN_OLD_conanrunenv_LD_LIBRARY_PATH
Remove-Item env:CONAN_OLD_conanrunenv_LD_LIBRARY_PATH
$env:PATH=$env:CONAN_OLD_conanrunenv_PATH
Remove-Item env:CONAN_OLD_conanrunenv_PATH
Remove-Item env:DYLD_LIBRARY_PATH