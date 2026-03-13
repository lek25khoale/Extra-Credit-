## Weighted Interval Scheduling

# Problem

Job j starts at sj, finishes at fj, and has weight (value) vj. Two jobs are compatible if they don't overlap. 

Goal: find the maximum weight subset of mutually compatible jobs.

Usually greedy would work if all weights are 1 but fails with differing weights so dynamic programming is required.

Jobs used: 

1: start=0 finish=3 weight=1

2: start=2 finish=5 weight=2

3: start=4 finish=7 weight=3

4: start=6 finish=9 weight=4

5: start=8 finish=11 weight=5

# Dynamic Programming Algorithm

Sort jobs by finish time

For each job j, compute p(j) using binary search to find the latest job compatible with j

Fill the schedule table bottom using the recurrence:

schedule[j] = max(v[j] + schedule[p(j)], schedule[j-1])

Trace back through the table with find_solution to recover which jobs were selected

At each step, pick the better option of either taking job j along with the best schedule that ends before it starts, or skip job j and keep the best schedule found so far.

# Picture of code running and result

![alt text](<Screenshot 2026-03-12 232605.png>)

# How to run the code

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git" (if already cloned it just cd to the extra credit file again)

cd "DP-WeightInterval"

g++ -o WI WeightInterval.cpp

./WI (or .\WI if it doesn't work)