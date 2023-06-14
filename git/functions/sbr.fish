function sbr
  set -l branch (git branch --format="%(refname:short)" | fzf +m --info=hidden --layout=reverse --height=10%)

  git checkout $branch
end