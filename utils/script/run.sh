#!/bin/sh

LOGPATH=./logs
CORPATH=./cor
VMSRC=./corewar_src
VM=../../corewar


BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
NORMAL="\033[0m"

function ft_dumped
{
	$VMSRC -d $CYCLES $CORPATH/$i $CORPATH/$j > $LOGPATH/zaz.txt
	ZAZ=$(grep -Ea "^0x" $LOGPATH/zaz.txt)
	ZAZ_WIN=$(grep -Ea "Contestant \d+, \".*\", has won \!" $LOGPATH/zaz.txt | cut -d ',' -f 1 | cut -d ' ' -f 2)
	$VM -d $CYCLES $CORPATH/$i $CORPATH/$j > $LOGPATH/us.txt
	US=$(grep -Ea "^0x" $LOGPATH/us.txt)
	US_WIN=$(grep -Ea "Player \d+(.+) is trop ze best\!" $LOGPATH/us.txt | cut -d '(' -f 1 | cut -d ' ' -f 2)
	if [ "$ZAZ" = "$US" ];then
		printf "$GREEN[V]$NORMAL\n"
	elif [ "$ZAZ_WIN" = "$US_WIN" ];then
		printf "$GREEN[V]$NORMAL\n"
	else
		printf "$RED[X]$NORMAL\n"
	fi
}

function ft_winners
{
	$VMSRC $CORPATH/$i $CORPATH/$j > $LOGPATH/zaz.txt
	ZAZ=$(grep -Ea "Contestant \d+, \".*\", has won \!" $LOGPATH/zaz.txt | cut -d ',' -f 1 | cut -d ' ' -f 2)
	printf "Zaz = $ZAZ, "
	$VM $CORPATH/$i $CORPATH/$j > $LOGPATH/us.txt
	US=$(grep -Ea "Player \d+(.+) is trop ze best\!" $LOGPATH/us.txt | cut -d '(' -f 1 | cut -d ' ' -f 2)
	printf "US = $US "
	if [ "$ZAZ" = "$US" ];then
		printf "$GREEN[V]$NORMAL\n"
	else
		printf "$RED[X]$NORMAL\n"
	fi
}

echo "       ___           ___           ___           ___           ___           ___           ___      "
echo "      /  /\         /  /\         /  /\         /  /\         /__/\         /  /\         /  /\     "
echo "     /  /:/        /  /::\       /  /::\       /  /:/_       _\_ \:\       /  /::\       /  /::\    "
echo "    /  /:/        /  /:/\:\     /  /:/\:\     /  /:/ /\     /__/\ \:\     /  /:/\:\     /  /:/\:\   "
echo "   /  /:/  ___   /  /:/  \:\   /  /:/~/:/    /  /:/ /:/_   _\_ \:\ \:\   /  /:/~/::\   /  /:/~/:/   "
echo "  /__/:/  /  /\ /__/:/ \__\:\ /__/:/ /:/___ /__/:/ /:/ /\ /__/\ \:\ \:\ /__/:/ /:/\:\ /__/:/ /:/___ "
echo "  \  \:\ /  /:/ \  \:\ /  /:/ \  \:\/:::::/ \  \:\/:/ /:/ \  \:\ \:\/:/ \  \:\/:/__\/ \  \:\/:::::/ "
echo "   \  \:\  /:/   \  \:\  /:/   \  \::/~~~~   \  \::/ /:/   \  \:\ \::/   \  \::/       \  \::/~~~~  "
echo "    \  \:\/:/     \  \:\/:/     \  \:\        \  \:\/:/     \  \:\/:/     \  \:\        \  \:\      "
echo "     \  \::/       \  \::/       \  \:\        \  \::/       \  \::/       \  \:\        \  \:\     "
echo "      \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/     "
echo "                                                                                                  V.M. Tests"
echo " "
echo " "

printf "Hello World! I will guide you in this script to test your corewar\n\n"
printf "Put your champions to test in the file './cor/'\n\n"
printf "Do you want to compare a dump? y/n\n"
read DUMP
if [ $DUMP = "y" ];then
	printf "\nHow much cycles do you want to test?\n"
	while [ 42 ];do
		read CYCLES
		if [ $CYCLES == "Q" ];then
			exit 1
		fi
		let CYCLES=$CYCLES+0
		if [ $CYCLES -lt 1 ];then
			printf "\nWrong number: enter a valid number (tap 'Q' if you want to quit)\n"
		else
			break 1
		fi
	done
fi
printf "\n\t\t******** LAUNCHING MAKE ********\n\n"
make -C ..
printf "\n\t\t******** LAUNCHING TESTS ********\n\n"

PLAYERS=( $(ls $CORPATH) )

for i in $(echo ${PLAYERS[@]})
do
	for j in $(echo ${PLAYERS[@]})
	do
		printf "$i vs $j ... "
		if [ "$DUMP" = "y" ];then
			ft_dumped
		else
			ft_winners
		fi
	done
	read a PLAYERS <<< "${PLAYERS[*]}"
done
