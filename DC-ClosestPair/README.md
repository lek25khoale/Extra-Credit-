## Closest Pair of Points

# Problem

Given n points in a 2D plane, find the pair of points with the smallest Euclidean distance between them. A brute force solution checks all pairs which makes the time complexity O(n²) and divide and conquer time complexity is to O(n log n)

Points used

A: (2, 3)

B: (4, 7)

C: (5, 1)

D: (7, 4)

E: (8, 9)

F: (10, 2)

G: (12, 6)

# Divide and Conquer Algorithm

Sort all points by x-coordinate

Split points into left and right halves along a vertical line L

Recursively find the closest pair in each half and call the smaller distance δ (delta)

Check the middle strip for any cross-half pair closer than δ

Return the overall minimum

# Picture of code working and result

![alt text](<Screenshot 2026-03-12 211358.png>)

# How to run the code 

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git" (if already cloned it just cd to the extra credit file again)

cd "DC-ClosestPair

g++ -o CP ClosestPair.cpp

./CP (or .\CP if it doesn't work)