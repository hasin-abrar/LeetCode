#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    int get_digit_count(int &pos, char ch, int val, vector<char>&chars){
        chars[pos++] = ch;
        int n = val;
        int _count = 0;
        vector<char> hold_vec;
        while(n){
            int digit = n%10;
            hold_vec.emplace_back('0' + digit);
            n/=10;
            _count++;
        }
        for(int i=hold_vec.size()-1; i>=0; i--){
            chars[pos++] = hold_vec[i];
        }
        return _count;
    }

    template<typename T>
    void print_vec(vector<T>& vec, int n){
        for(size_t i=0; i<n; i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    int compress(vector<char>& chars) {
        char prev = chars[0], curr = chars[0];
        int curr_count = 1, res = 0, pos = 0;
        for(int i=1; i<chars.size(); i++){
            curr = chars[i];
            if(curr == prev) curr_count++;
            else{
                if(curr_count == 1){
                    res++;
                    chars[pos++] = chars[i-1];
                }
                else{
                    res += 1 + get_digit_count(pos, chars[i-1], 
                            curr_count, chars);
                }
                curr_count = 1;
            }
            prev = curr;
        }

        if(curr_count == 1){
            res++;
            chars[pos++] = chars[chars.size()-1];
        }
        else{
            res += 1 + get_digit_count(pos, chars[chars.size()-1], 
                    curr_count, chars);
        }
        // print_vec(chars, res);
        return res;
    }
};

int main()
{
    Solution sol;

    vector<char> s = {'a', 'a', 'c', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    // vector<char> s = {'a', 'a', 'c', 'b', 'b'};
    cout<<sol.compress(s)<<endl;
    
    return 0;
}