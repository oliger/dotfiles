#!/bin/sh

if [ ! -d ~/.zsh-nvm ]
then
  echo "Installing NVM"
  git clone https://github.com/lukechilds/zsh-nvm.git ~/.zsh-nvm
fi

if test ! $(which yarn)
then
  echo "Installing Yarn"
  curl -o- -L https://yarnpkg.com/install.sh | bash -s -- --rc
fi

exit 0
