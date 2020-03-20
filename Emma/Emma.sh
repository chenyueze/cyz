#########################################################################
# File Name: EmmaFunc.sh
# Author: chenyueze
# mail: 1536667332@qq.com
# Created Time: 六  3/14 23:27:22 2020
#########################################################################
#!/bin/bash


body="________________________________________________________________________"
name=`whoami`
hello="Hello, master-${name}."



function Emma(){
	echo ${body}
	zsh ~/Emma/EmmaFunctions.sh
	echo ${body}
}




function helloEmma() {
	echo ${body}
	echo -e "\n\n\n\n\n\n"

	echo "			  ${hello}"

	echo -e "\n\n\n\n\n\n"
	echo ${body}
	zsh ~/Emma/EmmaGreet.sh
	echo ${body}
}
helloEmma




function EmmaPI(){
	declare -a PI
	PI=`cat ~/Emma/PI750`
	temp="Master expected numbers is :  "
	pass="Emma suggest you use :  Menis"
	for (( i = $1; i <= $2; i++ )); do
		temp=${temp}${PI[$i]}
		pass=${pass}${PI[$i]}
	done
	echo ${body}
	echo $temp
	echo ${pass}~@
	echo ${body}
}




function EmmaRunC(){
	g++ $1
	./a.out
}



function thanksEmma(){
	echo ${body}
	zsh ~/Emma/EmmaThanks.sh
	echo ${body}
}

function Emma2048(){
	echo ${body}
	echo "Master, can you set a new record this time?"
	echo ${body}
	EmmaRunC ~/Emma/Emma2048.cpp 
}

function Emmassh(){
	echo ${body}
	echo "conecting to aliyun ..."
	echo ${body}

	if [[ $1x -eq x ]] {
		ssh Emma@47.107.244.219
	}else{
		ssh $1@47.107.244.219
	}
	
}

