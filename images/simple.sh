#!/bin/bash 

COUNTER=100000

while [ 1 ]; do

    echo Hello $COUNTER

    sleep 5

    let COUNTER=COUNTER+1 
    
done