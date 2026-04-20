#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> word_vec;
        
        while(ss >> word) word_vec.emplace_back(word);

        // cout<<word_vec.size()<<endl;

        string result = "";
        for(int64_t i=word_vec.size()-1; i>=0; i--){
            // cout<<word_vec[i]<<endl;
            result += word_vec[i];
            if(i>0) result += " ";
        }
        return result;
    }
};

int main()
{
    Solution sol;

    string s = "hello world";
    cout<<sol.reverseWords(s)<<endl;
    
    return 0;
}