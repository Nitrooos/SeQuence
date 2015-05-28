#!/bin/bash

FOLDERS=$(find data -mindepth 1 -type d)
NUMS=(4 5 6 7 8 9)

rm -f -r results

mkdir -p results
for num in ${NUMS[*]}
do
  mkdir -p results/$num
  for fol in $FOLDERS
  do
    folder=${fol##*/}
    mkdir -p results/$num/$folder
    FILES=$(find data/$folder -name "*.*")
    for ff in $FILES
    do
      ffile=${ff##*/}
      echo Running \"SeQuence\" with m=$num on "$folder"/"$ffile"
      ./release/SeQuence -f data/"$folder"/"$ffile" -m $num -r results/"$num"/"$folder"/"$ffile"
    done
  done
done













