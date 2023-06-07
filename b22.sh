#!/bin/bash

myname=bandit23
mytarget=$(echo I am user $myname | md5 | cut -d ' ' -f 1)

echo "Copying passwordfile $myname to $mytarget"
