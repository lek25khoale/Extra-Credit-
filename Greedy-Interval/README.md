## Interval Scheduling

# Problem

Given a set of jobs, each job j starts at start time sj and finishes at finish time fj and two jobs compatible if they don't overlap and compatible jobs don't overlap

Goal: find maximum subset of mutually compatible jobs.

Intervals used:

A: 0, 6

B: 2, 4

C: 1, 5

D: 4, 6

E: 5, 10

F: 6, 9 

G: 9, 10

H: 8, 11

# Greedy Algorithm

Consider jobs in some order. Take each job provided it's compatible with the ones already taken.

[Earliest start time] Consider jobs in ascending order of start time sj.


[Earliest finish time] Consider jobs in ascending order of finish
time fj.

[Shortest interval] Consider jobs in ascending order of interval
length fj - sj.

[Fewest conflicts] For each job, count the number of conflicting
jobs cj. Schedule in ascending order of conflicts cj.

Sort intervals by finish time

Pick the first interval

Repeatedly pick the next interval whose start time is >= the finish time of the last chosen interval

# Pictures of code working and result

![alt text](<Screenshot 2026-03-12 192359.png>)

# How to run the code

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git"

cd "Greedy-Interval"

g++ -o Interval IntervalSchedule.cpp

./Interval (or .\Interval if it doesn't work)
