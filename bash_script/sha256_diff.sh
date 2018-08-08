#!/bin/bash

FILE="../ft_ssl"

if [ -e $FILE ]; then
	mv $FILE .
fi

echo "*** 1 hello ***"

agrument="-r hello"

echo $1 | shasum -a 256 hello > stfile
echo $1 | ./ft_ssl sha256 $agrument > myfile

diff -y stfile myfile

echo "*** 2 hello hello ***"

agrument="-r hello hello"

echo $1 | shasum -a 256 hello hello > stfile
echo $1 | ./ft_ssl sha256 $agrument > myfile

diff -y stfile myfile

echo "*** 3 hello test ***"

agrument="-r hello test"

echo $1 | shasum -a 256 hello test > stfile
echo $1 | ./ft_ssl sha256 $agrument > myfile

diff -y stfile myfile
