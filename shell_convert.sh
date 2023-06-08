#!/opt/homebrew/bin/bash

#bash code that replicates the shell in bandit level 33

while :
do
	read cmd
	echo -n ">> "
	${cmd^^} >&1
done
