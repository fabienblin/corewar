#!/bin/sh

make
for ((i=1; $i<26423; i+=1));
do 
	echo $i;
	$(./corewar_src Gagnant.cor corelol.cor -v 15 -d $i > txt1.txt)
	$(./corewar Gagnant.cor corelol.cor -v 15 -d $i > txt2.txt)
	#$(grep -a "0x0" txt1.txt > Zaz.txt)
	#$(grep -a "0x0" txt2.txt > Us.txt)
	$(grep "P.*| " txt1.txt | cut -c -12 > Zaz.txt)
	$(grep "P.*| " txt2.txt | cut -c -12 > Us.txt)
	$(diff Zaz.txt Us.txt > tmp.txt)
	if [ $? != 0 ]
	then
		cat tmp.txt
		echo "\007"
		kill -STOP $$
	fi
done
