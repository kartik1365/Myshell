#!/bin/sh
gcc example01.c
echo "Output for n = 1" > output01.txt
./a.out 1 >> output01.txt
echo "Output for n = 2" >> output01.txt
./a.out 2 >> output01.txt
echo "Output for n = 4" >> output01.txt
./a.out 4 >> output01.txt
echo "Output for n = 6" >> output01.txt
./a.out 6 >> output01.txt

