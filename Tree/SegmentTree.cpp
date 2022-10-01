// language: cpp
// time complexity: O(log n)
// space complexity: O(n)
// Segment Tree, also known as a statistic tree, is a tree data structure used for storing information about intervals, or segments. 
// It allows querying which of the stored segments contain a given point. It is a static structure.
// Segment Trees are data structures that let you easily find the minimum, maximum, or sum over a given subrange of a larger range.


// Problems on segment trees:
// https://www.spoj.com/problems/RMQSQ/
// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Segtree {
    public:
        Segtree(size_t size) {
            n = size;
            N = SuperCeiling(size);
            A.resize(2 * N, identity);
        }

        // index i = x in array A and also recomputes
        // every other value in the path up to the root from index i by
        // adding together the values of the two children below it.

        void Assign(size_t i, int x) {
            i = i+N;
            A[i] = x;
            for (i = Parent(i); i>0UL; i = Parent(i)) {
                A[i] = glue (A[LeftChild(i)], A[RightChild(i)]);
            }
        }

        // Finds sum_{i <= k <= j} A[k]
        // 1UL is an unsigned long int with a value of 1 represented at the bit level as:
        // 00000000000000000000000000000001
        int RangeSum(size_t i, size_t j) {
            return f (1UL, 0UL, (N-1), i, j);
        }


        // Prints the contents of the array A
        void printA() {
            for (size_t i=0; i < 2*N; i++) {
                cout << "A[" << i << "] = " << A[i] << endl;
            }
        }

    private:
        size_t n;
        size_t N;
        vector<int> A;
        int identity = 0;

        // Returns smallest power of 2 greater than equal to n
        size_t SuperCeiling(size_t n) {
            size_t p;
            for (p=1; p < n; p = p << 1);
            return p;
        }

        // Tree index functions
        size_t Parent(size_t i) {return i/2;}
        size_t LeftChild(size_t i) {return 2*i;}
        size_t RightChild(size_t i) {return 2*i+1;}

        // Function that glues associative operator on elements
        int glue(int a, int b) {
            return a+b;
        }

        int f (size_t v, size_t l, size_t r, size_t i, size_t j) {
        /*  We’re currently at A[v]. 1 <= v < 2*N.
            The range [l,r] is that of the current block, wrt user variables [0,n-1].
            The range [i,j] is the range of the query, wrt user variables [0,n-1].
            The size of the range [l,r] = r-l+1 is a power of 2.
            The range [l,r] contains the range [i,j].
            This function returns the answer to the query.
        */
            int t1, t2;
            size_t m;
            if (l==i && r==j) {
                return A[v];
            } else {
                m = (l+r)/2; // split [l,r] into [l,m] [m+1,r]
                t1 = (i <= m) ? f (LeftChild(v), l, m, i, (min(m,j))): identity;
                t2 = (j > m) ? f (RightChild(v), (m+1), r, (max(i,(m+1))), j): identity;
                return glue (t1, t2);
            }
        }
};

int main() {
    Segtree s(7);
    s.Assign(3,7);
    s.Assign(4,1);

    s.printA();
    
    printf("RangeSum(2,7) = %d\n", s.RangeSum(2,7));
    printf("RangeSum(0,3) = %d\n", s.RangeSum(0,3));
    printf("RangeSum(4,5) = %d\n", s.RangeSum(4,5));
    printf("RangeSum(5,5) = %d\n", s.RangeSum(5,5));
    return 0;
}