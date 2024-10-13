// Maximum Number of Vowels in a Substring of Given Length
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
    bool is_vowel(char ch){
        return ch == 'a' || ch == 'e' ||
            ch == 'i' || ch == 'o' ||
            ch == 'u';
    }

    int maxVowels(string s, int k) {
        int max_vowel, curr_vowel=0;
        for(int i=0; i<k; i++){
            if(is_vowel(s[i])){
                curr_vowel++;
            }
        }
        max_vowel = curr_vowel;
        for(int i=k; i<s.size(); i++){
            curr_vowel = curr_vowel - is_vowel(s[i-k]) + is_vowel(s[i]);
            if(curr_vowel > max_vowel) max_vowel = curr_vowel;
        }
        return max_vowel;
    }
};

int main()
{
    Solution sol;

    string s = "aeiou";
    int k = 2;
    cout<<sol.maxVowels(s, k)<<endl;
    
    return 0;
}