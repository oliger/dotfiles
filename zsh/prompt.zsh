autoload -U colors && colors

git_branch() {
  st=$(git status 2>/dev/null | tail -n 1)
  if [[ $st == "" ]]; then
    return
  else
    echo " - $(git symbolic-ref HEAD 2>/dev/null | awk -F/ {'print $NF'})"
  fi
}

git_status() {
  if $(! git status -s &> /dev/null)
  then
    return
  else
    if [[ $(git status --porcelain) == "" ]]
    then
      echo "%{$fg_bold[green]%}●%{$reset_color%} "
    else
      echo "%{$fg_bold[red]%}●%{$reset_color%} "
    fi
  fi
}

directory_name() {
  echo "%{$fg_bold[white]%}%1/%{$reset_color%}"
}

export PROMPT=$'\n$(git_status)$(directory_name)$(git_branch)\n> '

