//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int greatestOfThree(int A, int B, int C) {
        if(B>=A){
            if(B>=C) return B;
            else return C; 
        }
        else if(A>=B){
            if(A>=C) return A;
            else return C;
        }
        else return C;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.greatestOfThree(A, B, C) << "\n";
    }
}

// } Driver Code Ends