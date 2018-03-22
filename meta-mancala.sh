#!/usr/bin/env bash

clear

IFS=

input='-1'
player=2

while :
do
    g++ src/main.cpp --std=c++1z -DINPUT="$input" -DPLAYER="$player" -o meta-mancala

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

    if [ $player -eq 1 ]; then
        player=2
    else
        player=1
    fi
    echo "Player " $player ": "
    read -n2 input
done

