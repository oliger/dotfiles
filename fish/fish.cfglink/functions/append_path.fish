function append_path
  for path in $argv
    if not contains $path $PATH
      set --export --append PATH $path
    end
  end
end
