#!/bin/sh

sudo softwareupdate -i -a

osascript -e 'tell application "System Preferences" to quit'

# Hide Menu Bar.
defaults write NSGlobalDomain _HIHideMenuBar -int 1

# Hide Dock.
defaults write com.apple.dock autohide -int 1

# Remove hide delay.
defaults write com.apple.dock autohide-delay -float 0

# Hide recent apps.
defaults write com.apple.dock show-recents -int 0

# Disable press-and-hold.
defaults write -g ApplePressAndHoldEnabled -bool false

# Tap to click.
defaults write com.apple.driver.AppleBluetoothMultitouch.trackpad Clicking -int 1
defaults -currentHost write NSGlobalDomain com.apple.mouse.tapBehavior -int 1
defaults write NSGlobalDomain com.apple.mouse.tapBehavior -int 1

# Fast key repeat.
defaults write NSGlobalDomain KeyRepeat -int 1
defaults write NSGlobalDomain InitialKeyRepeat -int 10

# Enable full keyboard access.
defaults write NSGlobalDomain AppleKeyboardUIMode -int 3

# Disable auto-correct, smart dashes, quotes...
defaults write NSGlobalDomain NSAutomaticCapitalizationEnabled -int 0
defaults write NSGlobalDomain NSAutomaticDashSubstitutionEnabled -int 0
defaults write NSGlobalDomain NSAutomaticPeriodSubstitutionEnabled -int 0
defaults write NSGlobalDomain NSAutomaticQuoteSubstitutionEnabled -int 0
defaults write NSGlobalDomain NSAutomaticSpellingCorrectionEnabled -int 0

# Expand save save/print panels
defaults write NSGlobalDomain NSNavPanelExpandedStateForSaveMode -int 1
defaults write NSGlobalDomain NSNavPanelExpandedStateForSaveMode2 -int 1
defaults write NSGlobalDomain PMPrintingExpandedStateForPrint -int 1
defaults write NSGlobalDomain PMPrintingExpandedStateForPrint2 -int 1

# Open everything in list view.
defaults write com.apple.Finder FXPreferredViewStyle -string Nlsv

# Show hidden files.
defaults write com.apple.Finder AppleShowAllFiles true

# Use small icons in sidebar.
defaults write NSGlobalDomain NSTableViewDefaultSizeMode -int 1

# Disable resume.
defaults write NSGlobalDomain NSQuitAlwaysKeepsWindows -int 0

# Disable sound effects.
defaults write NSGlobalDomain com.apple.sound.beep.volume -int 0
defaults write NSGlobalDomain com.apple.sound.uiaudio.enabled -int 0
defaults write NSGlobalDomain com.apple.sound.beep.feedback -int 0

# Enable subpixel antialiasing
defaults write NSGlobalDomain AppleFontSmoothing -int 0 
defaults write NSGlobalDomain CGFontRenderingFontSmoothingDisabled -int 0

# Disable the “Are you sure you want to open this application?” dialog
defaults write com.apple.LaunchServices LSQuarantine -bool false

# Remove duplicates in the “Open With” menu (also see `lscleanup` alias)
/System/Library/Frameworks/CoreServices.framework/Frameworks/LaunchServices.framework/Support/lsregister -kill -r -domain local -domain system -domain user

/System/Library/PrivateFrameworks/SystemAdministration.framework/Resources/activateSettings -u

killall SystemUIServer Dock Finder