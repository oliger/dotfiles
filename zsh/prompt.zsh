# Allows variable substitution to take place in the prompt.
setopt prompt_subst

# Initialize colors.
autoload -U colors && colors

# If command fail, indicator become red.
local indicator="%(?,$,%{$fg[red]%}$%{$reset_color%})"

# Display the current git branch
git_branch() {
  st=$(/usr/bin/git status 2>/dev/null | tail -n 1)
  if [[ $st == "" ]]; then
    return
  else
    echo " - $(/usr/bin/git symbolic-ref HEAD 2>/dev/null | awk -F/ {'print $NF'})"
  fi
}

# Display a green dot if the working directory is clean and a red one if is not
# the case.
git_status() {
  st=$(/usr/bin/git status 2>/dev/null | tail -n 1)
  if [[ $st == "" ]]; then
    return
  else
    if [[ $st == "nothing to commit, working tree clean" ]]; then
      echo "%{$fg_bold[green]%}●%{$reset_color%} "
    else
      echo "%{$fg_bold[red]%}●%{$reset_color%} "
    fi
  fi
}

PROMPT='$(git_status)%3c$(git_branch)
${indicator} %{$reset_color%}'
