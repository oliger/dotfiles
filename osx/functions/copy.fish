function copy
  if not test -f $argv[1]
    echo "File does not exist"
    return 1
  end

  set -l absolute_path (realpath $argv[1])
  osascript -e "set the clipboard to (POSIX file \""$absolute_path"\")"
end