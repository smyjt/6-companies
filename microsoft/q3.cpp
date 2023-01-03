// https://leetcode.com/problems/bulls-and-cows/
// Return the number of bulls and cows in the given format

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        vector<int> a(10,0),b(10,0);
        int bulls=0,cows=0;
        for(int i=0;i<n;i++) {
            if(secret[i]==guess[i]) bulls++;
            else a[secret[i]-'0']++,b[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++) {
            cows+=min(a[i],b[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

int main() {
    string secret="1234",guess="0111";
    Solution obj;
    string ans=obj.getHint(secret,guess);
    cout<<ans<<endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)