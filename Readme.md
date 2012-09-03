# Jimmy's Dotfiles

This is my dotfiles including vim configuration, and other things.

## Environment

I am running on Mac OS X and zsh. If you would like to use it, you can do with the following command.

    chsh -s /bin/zsh

## Instalation

First, run the following command.

    git clone git://github.com/oliger/dotfiles ~/.dotfiles
    cd ~/.dotfiles
    rake install
    git submodule update --init

Then, change the `.gitconfig` to not commit as me.

Enjoy.

## Thanks to:

[Sam Soffes](https://github.com/samsoffes/dotfiles), [Zach Holman](https://github.com/holman/dotfiles), [Mathias Bynens](https://github.com/mathiasbynens/dotfiles), and other people who share their dotfiles.