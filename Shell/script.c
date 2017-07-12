#########################################################################
# File Name: script.sh
# Author: lixiao
# mail: 736343194@qq.com
# Created Time: Wed 12 Jul 2017 11:28:27 AM CST
#########################################################################
#!/bin/bash
sum=0
i=100
j=30
echo i=$i j=$j
(( sum=i+j))
res=$((i+j))
echo i+j:
echo sum:$sum
echo res:$res

(( sub=i-j ))
res=$((i-j))
echo i-j:
echo sub:$sub
echo sub:$res

((mul=i*j))
res=$((i*j))
echo i*j:
echo mul:$mul
echo res:$res

((div=i/j))
res=$((i/j))
echo i/j:
echo div:$div
echo div:$res

((mod=i%j))
res=$((i%j))
echo i%j:
echo mod:$mod
echo res:$mod


#myint=123
#mydouble=1.23
#mychar=d
#mystring='hello world'
#echo myint:$myint
#echo mydouble:$mydouble
#echo mychar:$mychar
#echo mystring:$mystring

#echo "this is a test"
#cd ..
#ls

