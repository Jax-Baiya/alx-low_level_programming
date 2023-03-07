#!/bin/bash
read -p "Enter directory path to add: " directory_path
git add "$directory_path"
git status
read -p "Enter commit message: " message
git commit -m "$message"
git push

