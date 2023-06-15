# Dotfiles

## Requirements

- [XCode](https://developer.apple.com/downloads).

## Installation

```sh
# Remove all apps from the Dock.
defaults write com.apple.dock persistent-apps -array

# Accept XCode license.
sudo xcodebuild –license

# Install dotfiles.
git clone https://github.com/oliger/dotfiles.git ~/.dotfiles
cd ~/.dotfiles
./scripts/install
```

## References

- https://sixcolors.com/post/2020/11/quick-tip-enable-touch-id-for-sudo/
- https://github.com/mathiasbynens/dotfiles
- https://github.com/paulirish/dotfiles
