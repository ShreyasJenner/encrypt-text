#!/bin/bash

read var
enc=$(echo "$var" | tr '\!-~' 'P-~\!-O')
dec=$(echo "$enc" | tr '\!-~' 'P-~\!-O')

echo "$enc"
echo "$dec"
