#!/bin/bash

submit=$1

question="$2"

dist="`pwd`/$question/*.input"

RED='\033[0;31m'

NC='\033[0m'

gcc -Wall -o test.out $submit

for file in $dist; do
    echo "Ready To Test..."
    ./test.out < $file > output
    if [[ $? == 0 ]]; then
        echo "Run Test Finish!"
        cmp --silent "$file.out" output
        if [ $? == 0 ];then
            echo "Test Success!!"
        else
            diff "$file.out" output
            echo "Test Fail!!!$"
        fi
    else
        echo "${RED}Run Test Fail!!${NC}"
    fi
done

rm test.out output
echo "Test Finish"