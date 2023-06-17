set --export HOMEBREW_PREFIX "/opt/homebrew"
set --export HOMEBREW_BUNDLE_NO_LOCK 1

append_path "$HOMEBREW_PREFIX/bin" "$HOMEBREW_PREFIX/sbin"
