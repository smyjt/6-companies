// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Evaluate the value of given expression in Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t:tokens) {
            if(t=="+" || t=="-" || t=="*" || t=="/") {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(t=="+") st.push(a+b);
                else if(t=="-") st.push(a-b);
                else if(t=="*") st.push(a*b);
                else if(t=="/") st.push(a/b);
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};

int main() {
    vector<string> tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution obj;
    int ans=obj.evalRPN(tokens);
    cout<<ans<<endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)