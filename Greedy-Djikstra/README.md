## Djikstra

# Problem

Find the shortest path distances from a source vertex src to all other vertices in a weighted undirected graph. All edge weights must be non-negative.

Nodes used:

A: 0

B: 1

C: 2

D: 3

E: 4

Edges used:

A-B: 2

A-C: 9

B-E: 7

B-C: 1

C-D: 5

D-E: 11

# Greedy Algorithm

Maintain a set S of explored nodes for which the shortest path distance d(u) from s to u has been determined.

Initialize S = { s }, d(s) = 0

Repeatedly choose the unexplored node v which minimizes: π(v) = min over edges (u,v) of d(u) + w(u,v)

Add v to S and set d(v) = π(v)

Choosing the node with the smallest π(v) at every step is the greedy choice which is greedy algorithm

# Picture of code working and the result

![alt text](<Screenshot 2026-03-12 201703.png>)

# How to run the code

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git" (if already cloned it just cd to the extra credit file again)

cd "Greedy-Djikstra"

g++ -o Djik Djikstra.cpp

./Djik (or .\Djik if it doesn't work)
