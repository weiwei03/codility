/*
Distinct
Compute number of distinct values in an array.
Write a function

int solution(vector<int> &A);

that, given a zero-indexed array A consisting of N integers, returns the number of distinct values in array A.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
For example, given array A consisting of six elements such that:

A[0] = 2    A[1] = 1    A[2] = 1
A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Complexity:

expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.


Pasted from: <https://codility.com/demo/results/training5AE3EF-H6F/>
 */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int len = A.size();
    if (0 == len) {
        return 0;    
    }
    
    int pre = A[0];
    int count = 1;
    
    for (int i = 1; i < len; ++i) {
        if (A[i] == pre) {
            continue;    
        }
        pre = A[i];
        ++count;
    }
    
    return count;
}
