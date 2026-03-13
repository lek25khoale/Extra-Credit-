## Knapsack

# Problem

Given n items each with a weight and value, and a knapsack with capacity W 

Goal: find the subset of items that maximizes total value without exceeding the weight limit. Each item can only be taken once.

Greedy (by value/weight ratio) does not guarantee the optimal solution. For example, items {5, 2, 1} by ratio gives value 35, but the optimal {3, 4} gives value 40

Items used:

1: weight=1 value=1

2: weight=2 value=6

3: weight=5 value=18

4: weight=6 value=22

5: weight=7 value=28

# Dynamic Programming Algorithm

Build a 2D table dp that store max value using the first i items with capacity w

For each item, pick the better option: take the item along with the best value for the remaining capacity, or skip it and keep the best value so far

Trace back through the table to find which items were taken

# Picture of code working and result

![alt text](<Screenshot 2026-03-12 235700.png>)

# How to run the code

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git" (if already cloned it just cd to the extra credit file again)

cd "DP-Knapsack"

g++ -o Knap Knapsack.cpp

./Knap (or .\Knap if it doesn't work)