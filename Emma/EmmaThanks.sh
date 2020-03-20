#########################################################################
# File Name: EmmaFunc.sh
# Author: chenyueze
# mail: 1536667332@qq.com
# Created Time: 六  3/14 23:27:22 2020
#########################################################################
#!/bin/bash
declare -a ThanksEmma
TEN=3
ThanksEmma=('Master, is Emma making you unhappy?'
			'Master, Emma will be by your side forever.'
			'Thank you too, master.')


rand=`od -An -N1 -i /dev/random`
let ThanksRand=rand%TEN+1
echo "${ThanksEmma[$ThanksRand]}"

