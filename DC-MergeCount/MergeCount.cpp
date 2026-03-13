#include <iostream>
#include <vector>
 
using namespace std;
 
void print_array(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < (int)arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < (int)arr.size()) cout << ", ";
    }
    cout << "]\n";
}
 
long long merge_and_count(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
 
    int i = 0, j = 0, k = low;
    long long count = 0;
 
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];// left element is smaller then no inversion
        } else {
            arr[k++] = right[j++];// right element is smaller then inversion
            for (int x = i; x < (int)left.size(); ++x){
                cout << left[x] << ", " << right[j - 1] << ")\n";
            }
            count += (left.size() - i); // remaining left elements form an inversion with right
        }
    }
 
    while (i < (int)left.size()){
        arr[k++] = left[i++];
    }
    while (j < (int)right.size()){ 
        arr[k++] = right[j++];
    }
 
    return count;
}
 

long long merge_count(vector<int>& arr, int low, int high) {
    // base case
    if (low >= high)
        return 0;
 
    int mid = (low + high) / 2;
 
    long long count = 0;
    count += merge_count(arr, low, mid);
    count += merge_count(arr, mid + 1, high); 
    count += merge_and_count(arr, low, mid, high); 
 
    return count;
}
 
int main() {
    vector<int> arr = {613, 5141, 42, 3, 211, 145,3248, 1, 0, 9999};
 
    cout << "Original array:\n";
    print_array(arr);
 
    cout << "\nInversion done:\n";
    long long inversions = merge_count(arr, 0, arr.size() - 1);
 
    cout << "\nSorted array:\n";
    print_array(arr);
 
    cout << "\nNumber of inversions: " << inversions << "\n";
 
    return 0;
}