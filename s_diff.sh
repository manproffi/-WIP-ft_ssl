#!/bin/bash

echo "*** 1 -s hello ***"

agrument="-s hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 2 -s hello -s hello ***"

agrument="-s hello -s hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 3 -rs hello ***"

agrument="-rs hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 4 -qs hello ***"

agrument="-qs hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 5 -rqs hello ***"

agrument="-rqs hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 6 -s -p hello ***"

agrument="-s -p hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 7 -rs -p -sr hello ***"

agrument="-rs -p -sr hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 8 -qr -p -s hello ***"

agrument="-qr -p -s hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 9 -qr -p file -s hello ***"

agrument="-qr -p file -s hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 10 -qr -ppshello file ***"

agrument="-qr -ppshello file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 10 -r -ppshello file ***"

agrument=" -ppshello file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile