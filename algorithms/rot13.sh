#!/bin/bash

read var

enc=$(echo "$var" | tr 'A-MN-Za-mn-z' 'N-ZA-Mn-za-m')
dec=$(echo "$enc" | tr 'A-MN-Za-mn-z' 'N-ZA-Mn-za-m')

echo "$enc"
echo "$dec"
