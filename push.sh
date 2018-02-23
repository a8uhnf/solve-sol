#!/bin/bash
echo "hello"
git ls-files -co --exclude-standard | grep '\.cpp$' | xargs git add
