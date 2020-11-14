#!/bin/sh

sudo softwareupdate -i -a

# Disable press-and-hold.
defaults write -g ApplePressAndHoldEnabled -bool false

# Fast key repeat.
defaults write NSGlobalDomain KeyRepeat -int 1

# Open everything in list view.
defaults write com.apple.Finder FXPreferredViewStyle Nlsv

# Use small icons in sidebar.
defaults write NSGlobalDomain NSTableViewDefaultSizeMode -int 1

# Enable subpixel antialiasing
defaults write -g AppleFontSmoothing -int 0 
defaults write -g CGFontRenderingFontSmoothingDisabled -bool NO