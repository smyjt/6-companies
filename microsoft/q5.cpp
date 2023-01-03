// https://leetcode.com/problems/largest-divisible-subset/
// Find the largest subset such that for every pair [x,y], x%y==0 or y%x==0

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> dp;

    vector<int> solve(int i, vector<int>& a) {
        if(i>=a.size()) return {};
        if(dp.count(i)) return dp[i];
        for(int j=i+1;j<a.size();j++) {
            if(a[j]%a[i]) continue;
            auto temp=solve(j,a);
            if(temp.size()>=dp[i].size()) dp[i]=temp;
        }
        dp[i].push_back(a[i]);
        return dp[i];
    }

    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<int> ans;
        for(int i=0;i<a.size();i++) {
            auto temp=solve(i,a);
            if(temp.size()>ans.size()) ans=temp;
        }
        return ans;
    }
};

int main() {
    vector<int> a={1,2,3,5,9,15,18};
    Solution obj;
    auto ans=obj.largestDivisibleSubset(a);
    for(int i:ans) cout<<i<<" ";
    return 0;
}

// Time Complexity: O(N^3)
// Space Complexity: O(N^2)