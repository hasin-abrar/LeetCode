// Longest Subarray of 1's After Deleting One Element
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
    // this is the same solution as 1004. Max Consecutive Ones III with k = 1
    int longestSubarray(vector<int>& nums) {
        int k = 1;
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
        return max_count - 1;
    }
};

int main()
{
    Solution sol;

    vector<int> s = {0,1,1,1,0,1,1,0,1};
    cout<<sol.longestSubarray(s)<<endl;
    
    return 0;
}