#!/usr/bin/env bash

clear

IFS=

input='None'
chance=1

while :
do
    g++ src/main.cpp --std=c++1z -o meta-mancala -DINPUT="$input" -DCHANCE="$chance"

    output=$?
    if [ $output -ne 0 ]; then
        echo "Winner - player: " $output
        break
    fi

    clear

    current_state=$(./meta-mancala)
    echo $current_state
    echo "R\"(" > current_state.txt
    echo $current_state >> current_state.txt
    echo ")\"" >> current_state.txt

    if [ $chance -eq 1 ]; then
        chance=2
    else
        chance=1
    fi
    echo "Player " $chance ": "
    read -n2 input
done

