/*
Find the minimal positive integer not occurring in a given sequence.

Write a function:

int solution(int A[], int N);

that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.

For example, given:

  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2
the function should return 5.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.


Pasted from: <https://codility.com/demo/results/trainingQ4BY23-24Q/>
*/

int solution(int A[], int N) {
    if (A == NULL || N == 0) {
        return 1;    
    }
    
    int *info = malloc(N * sizeof(int));
    int st = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 1 || A[i] > N) {
            continue;
        }
        
        int idx = A[i] - 1;
        info[idx] = 1;
        if (st == idx) {
            ++st;
            while(info[st] == 1) {
                ++st;    
            }
        }
    }
    
	free(info);
    return (st + 1);
}