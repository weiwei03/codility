/*
NumberOfDiscIntersections
Compute the number of intersections in a sequence of discs.
We draw N discs on a plane. The discs are numbered from 0 to N − 1. A zero-indexed array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:

  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0


There are eleven (unordered) pairs of discs that intersect, namely:

discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.
Write a function:

int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
 */

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
using namespace std;

struct Line {
    int center;
    int radius;
};

bool compare(const Line& l, const Line& r) {
    return ((l.center - r.center) <= (l.radius - r.radius));    
}

void printInfo(Line* info, int len) {
    for (int i = 0; i < len; ++i) {
        cout << i << "\t:" << info[i].center << "\t radius" << info[i].radius << endl;    
    }    
}
 
int findIdx(Line* info, const Line& val, int st, int end) {
    while(st <= end) {
        int mid = (end + st + 1) / 2;
        int posM = info[mid].center - info[mid].radius;
        if (posM < val.center) {
            st = mid + 1;
            //cout << "1 st:" << st << endl;
        } else {
            int tmp = val.center - posM + val.radius;
            if (tmp >= 0) {
                st = mid + 1;
            } else {
                end = mid - 1;    
            }
        }
    }
    
    return end;
}

int solution(vector<int> &A) {
    int len = A.size();
    Line *info = new Line[len];
    for (int i = 0; i < len; ++i) {
        info[i].center = i;
        info[i].radius = A[i];
    }
    
    sort(info, info + len, compare);
    //printInfo(info, len);
    
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int idx = findIdx(info, info[i], i + 1, len - 1);
        //cout << "idx:" << idx << endl;
        count += (idx - i);
        if (count > 10000000) {
            count = -1;
            break;
        }
    }
    
    delete[] info;
    info = NULL;
    
    return count;
}
