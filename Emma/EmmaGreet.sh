#########################################################################
# File Name: EmmaFunc.sh
# Author: chenyueze
# mail: 1536667332@qq.com
# Created Time: 六  3/14 23:27:22 2020
#########################################################################
#!/bin/zsh
declare -a EmmaGreet
EGN=5
EmmaGreet=('Master, are you going to save the world today?'
		   'What a nice day today! Although I dont know what the weather is...'
		   'Master, objectively speaking, you are more handsome than yesterday.'
		   'Emma love master! But what is love...'
		   'Master, please use Emma as much as possible.')
rand=`od -An -N1 -i /dev/random`
let rand=rand%EGN+1
echo ${EmmaGreet[${rand}]}
