#!/bin/sh

if [ ! -d ~/.zsh-nvm ]
then
  echo "Installing NVM"
  git clone https://github.com/lukechilds/zsh-nvm.git ~/.zsh-nvm
fi

exit 0
