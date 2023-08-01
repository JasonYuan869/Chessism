#!/bin/bash
input="./suite.txt"

while IFS= read -r line
do 
    valgrind ../../chessism  < ./$line.in -nographics
done < "$input"
