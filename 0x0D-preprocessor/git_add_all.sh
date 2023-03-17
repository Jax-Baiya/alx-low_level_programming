#!/bin/bash
git add -A
git status
read -p "Enter commit message: " message
git commit -m "$message"
git push

