#include <iostream>
#include <vector>
#define LOO(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef unsigned long long uint64_t;
typedef vector<vector<uint64_t> > matrix;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B, int M)
{
    matrix C(K+1, vector<uint64_t>(K+1));
    LOO(i, K) LOO(k, K) LOO(j, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
    return C;
}

// computes A ^ p
matrix pow(matrix A, uint64_t p, int M)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1, M), M);
    matrix X = pow(A, p/2, M);
    return mul(X, X, M);
}

int FibHuge(uint64_t N, int M)
{
    // create vector F1
    vector<uint64_t> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<uint64_t>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1, M);

    // the answer is the first row of T . F1
    uint64_t res = 0;
    LOO(i, K)
        res = (res + T[1][i] * F1[i]) % M;
    return res;
}

int main() {
    uint64_t n;
    int m;
    cin >> n >> m;
    cout << FibHuge(n, m) << '\n';
}
