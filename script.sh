#!/bin/bash
cd /home/grid/testbed/tb188/lab
ml icc
arr = ("fpu" "vme" "de" "pse" "tsc" "msr" "pae")
for i in "${arr[@]}"; do
for i in {1..3}; do
name1=$(date +%M)
name2=$(date +%S)
icpc -O$1 -m$j app.cpp -o go-$name1-$name2
echo "$j $i:"
time ./go-$name1-$name2
done
done 
`