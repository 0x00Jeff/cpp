#!/bin/bash

find . \( -name '*~' \) -delete &
find . \( -name ".*swp" \) -delete &
for i in 0x0/ex00 0x0/ex01 \
	0x1/ex00 0x1/ex01 0x1/ex02 0x1/ex03 0x1/ex04 0x1/ex05 \
	0x2/ex00 0x2/ex01 \
	0x3/ex00 0x3/ex01 0x3/ex02 \
	0x4/ex00 0x4/ex01 0x4/ex02 \
	0x5/ex00 0x5/ex01 0x5/ex02 0x5/ex03 \
	0x6/ex00
do
	make -C $i fclean &
done
find . \( -name "a.out" \) -delete &
find . \( -name "*.o" \) -delete &

wait

if [ $# != 1 ]
then
	echo "Usage : $0 commit-message"
	exit
fi

git add .

git commit -m "$1"

git push
