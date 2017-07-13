#########################################################################
# File Name: test.sh
# Author: lixiao
# mail: 736343194@qq.com
# Created Time: Thu 13 Jul 2017 09:37:26 AM CST
#########################################################################
#!/bin/bash
#计算1加到100，并且输出：1+2+3+4+....+100=5050
i=1;
sum=0
str=''
while [ $i -le 100 ]
do
	let sum+=i
	if [ -z $str ];then
		str=$i
		let i++
		continue
	fi
	str=$str'+'$i
	let i++
done
echo $str = $sum

#while循环语句的使用
#echo "while (( i<5 ))"
#i=0
#while(( i<5 ))
#do
#	echo $i
#	(( i++ ))
#done

#echo "while [ $i -le 5 ]"
#i=0
#while [ $i -le 5 ]
#do
#	echo $i
#	(( i++ ))
#done

#echo "死循环while [1 -lq 1]"
#while [ 1 -eq 1 ]
#do 
#	echo "hello world"
#	sleep 2
#done

#for语句的使用
#echo "for((i=0;i<5;i++))"
#for (( i=1;i<5;i++))
#do
#	echo $i
#done

#echo "for i in {1..5}"
#for i in {1..5}
#do
#	echo $i
#done

#for(( ; ; ))
#do
#	echo "hello world"
#	sleep 1
#done

#case语句的使用
#echo "请输入："
#read val
#case $val in
#	start )
#		echo "start....done"
#	;;
#	stop )
#		echo "stop....done"
#	;;
#	restart )
#		echo "restart....done"
#	;;
#	* )
#	echo "default...done"
#	;;
#esac

#if条件语句的使用
#read val
#if [ $val -eq 100 ];then
#	echo "yes,$val"
#else
#	echo "no val!"
#	if [ $val -gt 200 ];then
#		echo "data is big"
#	elif [ $val -lt 50 ];then
#		echo "data is small"
#	else
#		echo "opps!"
#	fi
#fi

#判断字符串
#echo "对于输入的数字和字符串进行比较"
#echo "请输入字符串：" 
#read val
#echo "输入的字符串为："$val
#echo "//判断输入的字符串是否等于hello->"
#test $val == hello 
#echo "退出码为："$?
#echo "判断输入的字符串是否不等于hello->"
#[ $val != hello ]
#echo "退出码为："$?

#判断数字
#echo "//判断输入的数字是否等于10->"
#test $val -eq 10
#echo "退出码为："$?
#
#echo "//判断输入的数字是否小于等于10->"
#test $val -le 10
#echo "退出码为："$?

