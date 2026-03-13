## Merge and Count

# Problem

Given an array of n numbers, count the number of inversions of pairs (i, j) where i < j but arr[i] > arr[j]. Brute force checks all pairs time complexity is O(n²) but divide and conquer only takes O(n log n).

Array used:

[613, 5141, 42, 3, 211, 145, 3248, 1, 0, 9999]

# Divide and Conquer Algorithm

If the array has one element, return 0 (base case)

Split the array into left and right halves

Recursively count inversions in the left half the rigt half

Merge the two sorted halves and count pairs where the larger element in the left half and the smallerr in the right

Return the sum of all three counts

# Picture of code running and result

![alt text](<Screenshot 2026-03-12 224806.png>)

# How to run the code

cd "folder location you want to save"

git clone "https://github.com/lek25khoale/Extra-Credit-.git" (if already cloned it just cd to the extra credit file again)

cd "DC-MergeCount"

g++ -o MC MergeCount.cpp

./MC (or .\MC if it doesn't work)

