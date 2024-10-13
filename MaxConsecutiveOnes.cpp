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
    template<typename T>
    void print_vec(vector<T>& vec, int n = 0){
        if(!n) n = vec.size();
        for(size_t i=0; i<n; i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    int longestOnes(vector<int>& nums, int k) {
        int _count = 0, max_count = 0, flipped=0;
        int zero_pos = 0;
        int start_pos = 0;
        for(int i=start_pos; i<nums.size(); i++){
            if(nums[i] == 1) _count++;
            else{
                if(k==0) {
                    if(_count > max_count) max_count = _count;
                    _count = 0;
                    continue;
                }
                flipped++;
                if(flipped > k){
                    flipped--;
                    while(1){
                        _count--;
                        if(nums[start_pos++] == 0) break;
                    }
                }
                _count++;
            }
            // cout<<i<<" "<<start_pos<<" "<<_count<<" "<<max_count<<endl;
            // cout<<endl;
            if(_count > max_count) max_count = _count;
        }
        return max_count;
    }

    int longestOnes_prev(vector<int>& nums, int k) {
        int _count = 0, max_count = 0, flipped=0;
        vector<int> zero_pos_vec(k+1);
        int zero_pos = 0;
        int start_pos = 0;
        for(int i=start_pos; i<nums.size(); i++){
            if(nums[i] == 1) _count++;
            else{
                if(k==0) {
                    if(_count > max_count) max_count = _count;
                    _count = 0;
                    continue;
                }
                flipped++;
                if(flipped > k){
                    flipped -= 1;
                    zero_pos %= k;

                    _count = _count - (zero_pos_vec[zero_pos] - start_pos + 1) + 1;
                    if(_count > max_count) max_count = _count;
                    start_pos = zero_pos_vec[zero_pos]+1;
                    
                    
                    zero_pos_vec[zero_pos++] = i;
                     
                    // cout<<"Flipped\n";
                    // cout<<i<<" "<<_count<<" "<<max_count<<endl;
                    // cout<<start_pos<<" "<<zero_pos<<endl;
                    // print_vec(zero_pos_vec);
                    // cout<<endl;
                    continue;
                }
                zero_pos_vec[zero_pos++] = i;
                _count++;
            }
            if(_count > max_count) max_count = _count;
            // cout<<i<<" "<<_count<<" "<<max_count<<endl;
            // cout<<start_pos<<" "<<zero_pos<<endl;
            // print_vec(zero_pos_vec);
            // cout<<endl;
        }
        return max_count;
    }
};

int main()
{
    Solution sol;

    vector<int> s = {1,1,1};
    int k = 1;
    cout<<sol.longestOnes(s, k)<<endl;
    
    return 0;
}