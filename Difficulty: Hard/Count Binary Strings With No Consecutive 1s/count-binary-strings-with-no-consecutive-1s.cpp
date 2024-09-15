//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int m = 1e9 + 7;

    // Helper function to perform matrix multiplication
    void multiply(long long F[2][2], long long M[2][2]) {
        long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % m;
        long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % m;
        long long z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % m;
        long long w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % m;

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }

    // Helper function to calculate matrix power
    void power(long long F[2][2], long long N) {
        if (N == 0 || N == 1)
            return;

        long long M[2][2] = {{1, 1}, {1, 0}};

        power(F, N / 2);
        multiply(F, F);

        if (N % 2 != 0)
            multiply(F, M);
    }

    // Function to find the Nth Fibonacci number using matrix exponentiation
    long long fib(long long N) {
        if (N == 0)
            return 0;

        long long F[2][2] = {{1, 1}, {1, 0}};
        power(F, N - 1);

        return F[0][0];
    }

    int countStrings(long long int N) {
        return fib(N + 2); // fib(N+2) gives the result as explained earlier
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends