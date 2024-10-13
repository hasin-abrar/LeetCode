#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool is_max_set = false;
        int _min = nums[0], _max = nums[0];
        for(int i=1; i<nums.size(); i++){
            // cout<<i<<" "<<_min<<" "<<_max << " "<<is_max_set<<endl;
            if(is_max_set && nums[i] > _max) return true;
            else if(nums[i] < _min){
                _min = nums[i];
            }
            else if(!is_max_set && nums[i] > _min){
                _max = nums[i];
                is_max_set = true;
            }
            else if(nums[i] < _max && nums[i] > _min){
                _max = nums[i];
            }
        }
        return false;
    }

    bool increasingTriplet_better(vector<int>& nums) {
        bool is_max_set = false;
        int a = INT32_MAX, b = INT32_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= a) a = nums[i];
            else if(nums[i] <= b) b = nums[i];
            else return true;
        }
        return false;
    }

};

int main()
{
    Solution sol;

    vector<int> s = {1,2,1,2,1,2,1,2,1,2};
    cout<<sol.increasingTriplet_better(s)<<endl;
    
    return 0;
}