#!/bin/sh

./corewar_src -d 1 champions/test.cor champions/test.cor > txt/src.txt
../corewar -d 1 champions/test.cor champions/test.cor > txt/cor.txt
cmp -l txt/src.txt txt/cor.txt > result
