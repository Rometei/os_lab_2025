#!/bin/bash


sum=0
count=$#

for arg in "$@"; do
    sum=$(awk "BEGIN {print $sum + $arg}")
done

average=$(awk "BEGIN {print $sum / $count}")

echo "Количество аргументов: $count"
echo "Среднее арифметическое: $average"