#########################################################################
# File Name: strip1.sh
# Author: lixiao
# mail: 736343194@qq.com
# Created Time: Sat 15 Jul 2017 10:57:29 AM CST
#########################################################################
#!/bin/bash
i=0
index=0
arr=( '|' '/' '-' '\\')
str=''
while [ $i -le 100 ]
do
	index=i%4
	printf "%-100s][%d%%][%c]\r" "$str" "$i" "${arr[$index]}"
	str+="#"
	let i++
	sleep 1
done
