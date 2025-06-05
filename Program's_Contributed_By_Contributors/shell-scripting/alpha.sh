#!/bin/bash
echo " program to check whether character entered is Upper, Lower, Digit, Consonant, or Vowel "
read ch
if [[ $ch == [A-Z] ]]
then
	echo "uppercase"
elif [[ $ch == [a-z] ]]
then
	echo "lowercase"
elif [[ $ch == [0-9] ]]
then
	echo "digit"
fi
if [[ $ch != [0-9] ]]
then
       if [[ $ch == [AEIOUaeiou] ]]
       then
        	echo "vowel"
       else
        	echo "consonant"
       fi
else
	echo "neither vowel nor consonant"
fi
