#!/bin/bash

find . \( -name '*~' \) -delete
find . \( -name ".*swp" \) -delete
find . \( -name "*.o" \) -delete
find . \( -name "a.out" \) -delete
make -C 0x0/ex00 fclean
make -C 0x0/ex01 fclean

if [ $# != 1 ]
then
	echo "Usage : $0 commit-message"
	exit
fi

git add .

git commit -m "$1"

git push
