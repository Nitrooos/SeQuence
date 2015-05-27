#!/bin/bash

INSTANCES=data/*/*

for i in $INSTANCES
do
    echo "Processing $i file"
    
    for m in `seq 9 -1 1`
    do
        echo "    with minimum common part: $m"
        debug/SeQuence -f $i -m $m -r "output/${i##*/}"
    done
done