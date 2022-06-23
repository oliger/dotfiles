#!/bin/sh

if [ ! -d ~/.volta ]
then
  echo "Installing Volta"
  curl https://get.volta.sh | bash
fi

exit 0
