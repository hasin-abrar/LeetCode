#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1_count(27,0), w2_count(27,0);
        for(auto ch: word1){
            w1_count[ch - 'a']++;
        }
        for(auto ch: word2){
            w2_count[ch - 'a']++;
        }
        for(int i=0; i<w1_count.size(); i++){
            if((w1_count[i] == 0 && w2_count[i]>0) 
                ||(w2_count[i] == 0 && w1_count[i]>0) ) return false;
        }
        sort(w1_count.begin(), w1_count.end());
        sort(w2_count.begin(), w2_count.end());
        for(int i=0; i<w1_count.size(); i++){
            if(w1_count[i] != w2_count[i]) return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    string s1 = "cabbba";
    string s2 = "abbqcc";
    cout<<sol.closeStrings(s1, s2)<<endl;
    
    return 0;
}