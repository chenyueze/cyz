# 完整代码

```shell
#!/bin/bash
declare -a prime
End=1000
Sum=0

for (( i=2; i<${End}; i++ )); do
	if [[ ${prime[$i]}x == x ]]; then
		prime[0]=$[ ${prime[0]} + 1 ]
		prime[${prime[0]}]=$i
		Sum=$[ ${Sum} + $i ]
	fi
	for (( j=1; j<=${prime[0]}; j++ )); do
		if [[ $[ $i * ${prime[$j]} ] -gt ${End} ]]; then
			break
		fi
		prime[$[ $i * ${prime[$j]} ]]=1
		if [[ $[ $i % ${prime[$j]}] -eq 0 ]]; then
			break
		fi
	done
done
```

# 代码分析

## 每次取变量值必须用${}

## 变量不用声明类型

## 做数学运算：sum=$[ $i + $2 ]

## 赋值运算不能有空格

## 字符拼接x是否等于x：判断字符是否为空

## zsh中的数组没有0位