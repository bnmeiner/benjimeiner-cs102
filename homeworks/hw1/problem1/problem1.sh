#!/usr/bin/env bash 

mkdir hw1_unix
cp -r hw1_unix hw1_unix_copy
cd hw1_unix_copy
touch file1.txt
cp file1.txt ../hw1_unix/file1_copy.txt
cp file1.txt ../hw1_unix/file1_copy2.txt
cd ..
echo "directories:"
ls -la
echo "files in hw1_unix:"
ls hw1_unix


