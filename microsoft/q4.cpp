// https://leetcode.com/problems/rotate-function/
// Find the maximum F(i), 0<=i<N where F(i) is the summation of i*arrk[i], arrk[i] being k times rotated array

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // The relation is f(k)=f(k-1)+sum-n*arrk[0]
    // arrk[0] is the first element of k times rotated array
    int maxRotateFunction(vector<int>& a) {
        int n=a.size();
        int sum=0,f=0;
        for(int i=0;i<n;i++) {
            sum+=a[i];
            f+=i*a[i];
        }
        int ans=f;
        for(int i=n-1;i>0;i--) {
            f=f+sum-n*a[i];
            ans=max(ans,f);
        }
        return ans;
    }
};

int main() {
    vector<int> a={4,3,2,6};
    Solution obj;
    int ans=obj.maxRotateFunction(a);
    cout<<ans<<endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)