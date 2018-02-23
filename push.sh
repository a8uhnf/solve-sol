#!/bin/bash
echo "------------"
git ls-files -co --exclude-standard | grep '\.cpp$' | xargs git add
git commit -m "add .cpp files"
git push origin HEAD

