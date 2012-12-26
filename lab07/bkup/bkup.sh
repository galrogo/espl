#!/bin/bash

#bkup

filename=$1
numcopies=$2

for ((i=numcopies; i>1; i--)) 
do
    j=$(( $i - 1 ))
    if [ -f $filename.$j ]; then
    cp $filename.$j $filename.$i
    fi
done

cp $filename $filename.1

exit 0