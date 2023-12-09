#!/bin/bash

find . \( -name '*~' \) -delete
find . \( -name ".*swp" \) -delete
find . \( -name "*.o" \) -delete
find . \( -name "a.out" \) -delete
for i in 0x0/ex00 0x0/ex01 \
	0x1/ex00 0x1/ex01 0x1/ex02 0x1/ex03 0x1/ex04 0x1/ex05 \
	0x3/ex00/
do
	make -C $i fclean
done

if [ $# != 1 ]
then
	echo "Usage : $0 commit-message"
	exit
fi

git add .

git commit -m "$1"

git push
