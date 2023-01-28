setopt AUTO_CD

# Expand parameters and substitute commands in prompt.
setopt PROMPT_SUBST

# Move cursor to the end after completion.
setopt ALWAYS_TO_END

# Do not add command to the history if it is a duplicate of the previous one.
setopt HIST_IGNORE_DUPS

# Do not add command to the history if it starts with a space.
setopt HIST_IGNORE_SPACE

bindkey "^A" beginning-of-line
bindkey "^E" end-of-line