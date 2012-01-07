# Allows variable substitution to take place in the prompt.
setopt prompt_subst

# Initialize colors.
autoload -U colors && colors

# If command fail, indicator become red.
local indicator="%(?,$,%{$fg[red]%}$%{$reset_color%})"

# Check if is git
is_git() {
  if [[ $(/usr/bin/git status 2>/dev/null | tail -n 1) == "" ]]; then
    return 1
  else
    return 0
  fi
}

# Display the current git branch
git_branch() {
  is_git || return
  echo " - $(/usr/bin/git symbolic-ref HEAD 2>/dev/null | awk -F/ {'print $NF'})"
}

# Display a green dot if the working directory is clean and a red one if is not
# the case.
git_status() {
  is_git || return
  if [[ $st == "nothing to commit (working directory clean)" ]]; then
    echo "%{$fg_bold[green]%}●%{$reset_color%} "
  else
    echo "%{$fg_bold[red]%}●%{$reset_color%} "
  fi
}

PROMPT='
$(git_status)%~$(git_branch)
${indicator} %{$reset_color%}'
