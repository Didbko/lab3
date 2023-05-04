#!/bin/bash
cat /proc/cpuinfo | grep flag | head -1
cd /home/grid/testbed/tb188/lab 
ml icc
arr=("-O1" "-O2" "-O3" "-xSSE2" "-xSSE3" "-xAVX"  )
for j in "${arr[@]}"; do
   x1=$(date +%M)
   x2=$(date +%S)
   echo icpc -std=c++17 $j ConsoleApplication1.cpp -o log-$x1-$x2
   icpc -std=c++17 $j ConsoleApplication1.cpp -o log-$x1-$x2
   echo "$j $i:"
   time ./log-$x1-$x2
done