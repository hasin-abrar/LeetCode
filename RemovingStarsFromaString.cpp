#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> string_stack;
        for(char ch: s){
            if(ch == '*' && string_stack.size() > 0) string_stack.pop();
            else string_stack.push(ch);
        }
        string sol = "";
        while(string_stack.size()){
            sol += string_stack.top();
            string_stack.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};

int main(){
    Solution sol;
    string s = "erase*****";
    cout<<sol.removeStars(s)<<endl;
    return 0;
}