#/*************************************************************************
#	> File Name: strip1.c
#	> Author: lixiao
#	> Mail: 736343194@qq.com
#	> Created Time: Sat 15 Jul 2017 09:43:48 AM CST
#************************************************************************/

#include<stdio.h>
lable=( '|' '\\' '-' '/' )
str=''
str1=''
str2=''
k=0

for i in {1..100}
do
	str+=" "
done

for j in {0..200}
do
	let n=j%4
	printf "\033[1;47m%s\033[0m [%d%%] [%c] \r" "$str" "$k" "${lable[$n]}"
	printf "\033[1;46m%s\033[0m\r" "$str1"
	printf "\033[1;44m%s\033[0m\r" "$str2"
	if [ $j -lt 100 ] ; then
		str1+=' '
	fi
	if [ $j -ge 20 -a $j -lt 120 ] ; then
		str2+=' '
		let k++
	elif [ $j -ge 120 ] ; then
		break
	fi
	sleep 1
done
echo " "
