// https://leetcode.com/problems/perfect-rectangle/
// Return true if all the rectangles together form an exact cover of a rectangular region without overlapping

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Line sweep algorithm
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mark;
        for(auto r:rectangles) {
            mark[{r[0],r[1]}]++; // Bottom left
            mark[{r[0],r[3]}]--; // Top left
            mark[{r[2],r[1]}]--; // Bottom right
            mark[{r[2],r[3]}]++; // Top right
        }
        int vertices=0;
        for(auto m:mark) {
            if(m.second) {
                if(abs(m.second)!=1) return false;
                vertices++;
            }
        }
        return vertices==4;
    }
};

int main() {
    vector<vector<int>> rectangles={{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    Solution obj;
    bool ans=obj.maxRotateFunction(rectangles);
    cout<<ans<<endl;
    return 0;
}

// Time Complexity: O(NlogN)
// Space Complexity: O(N)