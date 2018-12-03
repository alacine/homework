#!/bin/bash
for txt in $(ls *.txt | cut -d '.' -f 1); do
    python dfa.py $txt.dot < $txt.txt
    echo "---------------------------------"
done
for dot in $(ls *.dot | cut -d '.' -f 1); do
    dot -Tpng $dot.dot -o $dot.png
done
