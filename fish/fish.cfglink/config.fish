set --unexport fish_greeting

set --export DOTFILES $HOME/.dotfiles

set --local fish_files $DOTFILES/*/*.fish
set --local env_file_regex ".+/env.fish"

# Set up `PATH` and other environment variables to ensure that binaries are
# available in the other fish files.
for env_file in (string match --regex $env_file_regex $fish_files)
  source $env_file
end

# Initialize modules by sourcing their fish files. As `.env.fish` has already
# been sourced, binaries and environment variables will be available.
for file in (string match --invert --regex $env_file_regex $fish_files)
  source $file
end

# Load fish functions and completions defined in modules.
set fish_function_path $fish_function_path $DOTFILES/*/functions
set fish_complete_path $fish_complete_path $DOTFILES/*/completions
