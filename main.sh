

# 1. Take the filename as an argument and move the file to my-deleted-files directory.
# 2. If the file doesn't exist then tell the user to enter the correct file name.

# 3. Move the file to my-deleted-files directory with the version number appended to it.

# 4. If the first argument is -c then clear the entire my-deleted-files directory.





# input format: ./4.sh file_name or ./4.sh -c
# output format: file_name moved to my-deleted-files directory or file_name doesn't exist in the current directory

# input will come to $1



#!/bin/bash

DIR_NAME="my-deleted-files"

# function to get number of files matching with $1 in directory if no files then return 0

function get_file_count(){

    # check if file exists in directory my-deleted-files
    filename=$1  
    
    CountVersion=0

    name=$(echo $filename|cut -d'.' -f1)
    extension=$(echo $filename|rev|cut -d'.' -f1|rev)

    for n in $( ls $DIR_NAME | cut -d'.' -f1 | cut -d'_' -f1 )
    do
        if [ "$name" == "$n" ]
        then 
            CountVersion=$(( CountVersion+1 ))
        fi
    done
    
    
    echo $CountVersion
}



# check if my-deleted-files directory exists or not and create it if it doesn't exist

if [ ! -d $DIR_NAME ]
then
    mkdir $DIR_NAME
fi

# check if the first argument is -c

if [ "$1" == "-c" ]
then
    # clear the entire my-deleted-files directory
    rm -rf $DIR_NAME
    echo "my-deleted-files directory cleared"
    exit 0
fi

# check if the file exists or not in the current directory

if [ -f "$1" ]
then
    # move the file to my-deleted-files directory
    filename=$1  
    
    name=$(echo $filename|cut -d'.' -f1)
    extension=$(echo $filename|rev|cut -d'.' -f1|rev)
    CountVersion=$( get_file_count $filename )
    
    final_name=$name"_"$CountVersion"."$extension
    
    mv $filename $final_name
    mv $final_name $DIR_NAME
    echo "$filename moved to my-deleted-files directory"
else
    echo "Enter valid filename: "
fi

# 1. Take the filename and check if it exists in the current directory.
# 2. Check if my-deleted-files directory exists or not and create it if it doesn't exist.
# 3. Check if the first argument is -c then clear the entire my-deleted-files directory using rm -rf.
# 4. If the file exists then move the file to my-deleted-files directory with the version number appended to it.
# 5. I have used the following command to get the version number of the file:
#     ls my-deleted-files | cut -d'.' -f1 | cut -d'_' -f1
# 6. If the file doesn't exist then tell the user to enter the correct file name.
# 7. If the file exists then move the file to my-deleted-files directory with the version number appended to it.