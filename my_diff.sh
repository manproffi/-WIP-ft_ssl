#!/bin/bash

echo "*** 1 empty ***"

echo $1 | md5 > stfile
echo $1 | ./ft_ssl md5 > myfile

diff -y stfile myfile

echo "*** 2 -q ***"

agrument=-q 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 3 -r ***"
agrument=-r

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 4 -p ***"
agrument=-p

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 5 -s string ***"
agrument="-s string"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 6 -p -p ***"
agrument="-p -p"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 7 -p -p -p ***"
agrument="-p -p -p"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 8 -q -p -p -p ***"
agrument="-q -p -p -p"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 9 -qr -p -p -p ***"
agrument="-qr -p -p -p"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 10  -p -p -p -qr***"
agrument=" -p -p -p -qr"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 11  -p -p -p -qr -s string ***"
agrument=" -p -p -p -qr -s string"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 12   -pqrs string ***"
agrument=" -pqrs string"

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 13  -sstring -pqrs ***"
agrument=" -sstring -pqrs "

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile