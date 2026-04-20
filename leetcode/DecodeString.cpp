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
    string process_string(string &s, int& i){
        string val_str = "";
        string str = "";
        for(; i<s.size(); i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9') val_str += ch;
            else if (ch == '[') break;
            else str += ch;
        }
        int val = 0;
        if(val_str.size() > 0)
            val = stoi(val_str);
        // cout<<i<<" bs before "<<val<<endl;
        return str + bracket_start(s, ++i, val);
    }

    string bracket_start(string &s, int& i, int val){
        string str = "";
        for(; i<s.size(); i++){
            char ch = s[i];
            // cout<<i<<" "<<ch<<" : "<<str<<endl;
            if(ch >= '0' && ch <= '9'){
                // cout<<i<<" ps before: "<<str<<endl;
                str += process_string(s, i);
                // cout<<i<<" ps after: "<<str<<endl;
            } 
            else if(ch == ']'){
                // cout<<i<<" be before: "<<str<<endl;
                str += bracket_end(s, val, str);
                // cout<<i<<" be after: "<<str<<endl;
                break;
            }
            else str += ch;

        }
        return str;
    }

    string bracket_end(string &s, int val, string str){
        string repeat = "";
        for(int i=0; i<val-1; i++) repeat += str;
        return repeat;
    }


    string decodeString(string s) {
        int i=0;
        string ans = "";
        while(i < s.size()){
            ans += process_string(s, i);
            i++;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "2[2[ab]2[3[c]]]";
    std::cout<<sol.decodeString(s)<<endl;
    return 0;
}
