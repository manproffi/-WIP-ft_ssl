#!/bin/bash

echo "*** 1 file ***"

agrument="file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 2 -q file ***"

agrument="-q file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 3 -r file ***"

agrument="-r file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 4 -rq file ***"

agrument="-rq file" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 5 file hello***"

agrument="file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 6 -r file hello***"

agrument="-r file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 7 -q file hello***"

agrument="-q file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 8 -qr file hello***"

agrument="-qr file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 9 -p -qr file hello***"

agrument="-p -qr file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 10 -p -p -qr file hello***"

agrument="-p -p -qr file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

echo "*** 11 -s hello -p -p -qr file hello***"

agrument="-s hello -p -p -qr file hello" 

echo $1 | md5 $agrument > stfile
echo $1 | ./ft_ssl md5 $agrument > myfile

diff -y stfile myfile

