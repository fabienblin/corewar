#!/bin/sh

red="\e[1;31m"
green="\e[1;32m"
red="\e[1;31m"
blue="\e[1;34m"
yellow="\e[1;33m"
white="\e[1;37m"
normal="\e[1;0m"

dir_name=cor

if [ $1 ]
then
	secondes=$1
else
	secondes=0
fi

if [ $# == 2 ]
then
	shift
	args=($@)
	else
	args=($(ls ./champions/))
fi

if [ ! -d "$dir_name" ]
then
	mkdir "$dir_name"
	printf "${white} Directory $dir_name created ! ${normal}\n"
else
	rm $dir_name/*
fi

length=$((${#args[@]} - 1))
for i in $(seq 0 $length)
do
	elem=${args[i]%.*}
	echo  "<-------------------------------"
	printf "${red}"
	echo "\tTEST DE : {$elem}\n"
	printf "${green}"
	echo "**************<ASM>*************"
	echo $(./my_asm/asm ./champions/$elem.s || mv ./champions/$elem.cor cor;)
	printf "${yellow}"
	echo "************<ASM_SRC>***********"
	echo "$(./asm_src/asm_src ./champions/$elem.s  && mv ./champions/$elem.cor cor/$elem\src.cor;)\n"
	if [ -f "./cor/$elem.cor" ] && [ -f "./cor/${elem}src.cor" ]
	then
		printf "${red}"
	echo "************<DIFF>*************"
		echo "$(diff cor/$elem.cor cor/$elem\src.cor)"
		printf "${blue}\n"
	echo "************<CMP>**************"
		echo "$(cmp -l cor/$elem.cor cor/$elem\src.cor)"
	fi
		printf "${white}\n"
	echo "************<VALGRIND>**************"
		echo "$(valgrind --leak-check=full --track-origins=yes ./my_asm/asm ./champions/$elem.s;)"
	printf "${normal}"
	echo "------------------------------->\n\n"
	echo "$(rm ./champions/$elem.cor;)"

	sleep $secondes
done
