#!/bin/bash
rm ./a.out
yacc parser.y
lex parser.l
gcc y.tab.c -ll -ly -w
./a.out TestCase1.c
./a.out TestCase2.c
./a.out TestCase3.c
./a.out TestCase4.c
./a.out TestCase5.c
./a.out TestCase6.c
