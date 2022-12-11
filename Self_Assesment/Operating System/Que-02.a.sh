#!/bin/bash

function partition {
	let i=$2-1
	let pivot=${x[$3]}
	
	for(( j="$2"; j<"$3"; j++ ))
	do
		if [ "${x[$j]}" -lt "$pivot" ]
		then
			let i=i+1
			let temp=${x[$i]}
			x[$i]=${x[$j]}
			x[$j]=$temp
		fi
	done

	let temp=${x[$((i+1))]}
	x[$((i+1))]=${x[$3]}
	x[$3]=$temp
	
	k=$((i+1))
	

}

function quicksort {
	if [ "$2" -lt "$3" ]
	then
		partition x $2 $3		
		let pi=k
		quicksort x $2 $((pi-1))
		quicksort x $((pi+1)) $3
	fi
	
}

x=(3 5 1 7 11 3 2)
quicksort x 0 6

echo -n "Sorted array: "
for i in "${x[@]}"
do
	echo -n "$i "
done
echo