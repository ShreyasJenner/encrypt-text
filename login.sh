#!/bin/bash

#first bash script file I created
#bash script to automatically login into overthewire server

#File that stores passwords of each level
#A line in a file corresponds to a bandit level password (this is needed for 
#the sed command to store the correct password in variable "password")
#For eg: line 3 stores password for bandit3
file="pass"

echo "Enter Bandit Level No to be accessed:"
#reads the level entered and stores it in variable level
read level								

#creates a variable password that extracts the particular line corresponding to 
#the level number entered
password=$( sed -n "${level}p" $file )

#sshpass is usually unsafe and not recommended as a means to login with ssh as 
#the password can be easily seen with the history command, but given that the
#command is running inside the script, it doesn't get logged into history
sshpass -p $password ssh bandit$level@bandit.labs.overthewire.org -p 2220
