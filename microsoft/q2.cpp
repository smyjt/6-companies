// https://leetcode.com/problems/combination-sum-iii/
// Find all valid combinations of k numbers that sum up to n such that the only numbers 1 through 9 are used and each number is used at most once.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> ans;

    void solve(int k, int n, vector<int>& c) {
        if(c.size()==k && n==0) {
            ans.push_back(c);
            return;
        }
        for(int i=c.empty()?1:c.back()+1;i<=9;i++) {
            if(n-i<0) return;
            c.push_back(i);
            solve(k,n-i,c);
            c.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> c;
        solve(k,n,c);
        return ans;
    }
};

int main() {
    int k=3,n=9;
    Solution obj;
    auto ans=obj.combinationSum3(k,n);
    for(auto v:ans) {
        for(int i:v) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// Time Complexity: O(K*9^K)
// Space Complexity: O(K)