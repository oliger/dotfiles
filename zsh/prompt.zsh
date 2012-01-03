# Adds the current branch name in green
git_prompt_info() {
  ref=$(git symbolic-ref HEAD 2> /dev/null)
  if [[ -n $ref ]]; then
    echo "[%{$fg_bold[green]%}${ref#refs/heads/}%{$reset_color%}] "
  fi
}

# Expand functions in the prompt
setopt prompt_subst

# Prompt
export PROMPT='
$(git_prompt_info)%~
▸ '
