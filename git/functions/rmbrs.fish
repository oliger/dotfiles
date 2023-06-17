function rmbrs
    git fetch -p

    for branch in (git branch -v | grep '\[gone\]' | awk '{print $1}')
        git branch -D $branch
    end
end