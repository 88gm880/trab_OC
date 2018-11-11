#!/bin/bash
echo "Digite o valor desejado para TAM: "; read tam
sed -i "s/#define TAM.*/#define TAM $tam/" p1.c
sed -i "s/#define TAM.*/#define TAM $tam/" p2.c
gcc p1.c -o p1
gcc p2.c -o p2
echo "$tam," >> testes.csv
for i in 1 2 3 4; do
./p1
done
echo "$tam," >> testes.csv
for i in 1 2 3 4; do
./p2
done
