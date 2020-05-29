if [[ -a ~/.zsh-nvm ]]
then
  source ~/.zsh-nvm/zsh-nvm.plugin.zsh
fi

if (( $+commands[yarn] ))
then
  export PATH="$PATH:`yarn global bin`"
fi