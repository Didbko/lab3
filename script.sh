#!/bin/bash
ml icc
arr = ("fpu" "vme" "de" "pse" "tsc" "msr" "pae")
for i in "${arr[@]}"; do
for i in {1..3}; do
name1=$(date +%M)
name2=$(date +%S)
icpc -std=c++17 -O$i -m$j app.cpp -o go-$name1-$name2
echo "$j $i:"
time ./go-$name1-$name2
done
done 
