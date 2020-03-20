#########################################################################
# File Name: EmmaFunc.sh
# Author: chenyueze
# mail: 1536667332@qq.com
# Created Time: 六  3/14 23:27:22 2020
#########################################################################
#!/bin/zsh
declare -a EmmaFunction
EFN=3
EmmaFunction=('1. EmmaPI [int_1] [int_2] : Output a set of strings based on PI.'
			   '2. EmmaRunC [xxx.cpp] : Compile and run C program.'
				'3. Emma2048 : Master, challenge yourself.')
echo "Master, my functions include : "
for (( i = 1; i <= ${EFN}; i++  )); do
	echo ${EmmaFunction[$i]}
done
