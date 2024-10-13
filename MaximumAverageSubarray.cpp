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
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum = 0, curr_sum;
        for(int i=0; i<k; i++){
            max_sum += nums[i];
        }
        curr_sum = max_sum;
        for(int i=k; i<nums.size(); i++){
            curr_sum = curr_sum - nums[i-k] + nums[i];
            if(curr_sum > max_sum) max_sum = curr_sum;
            // cout<<i<<" "<<nums[i]<<" "<<curr_sum<<" "<<max_sum<<endl;
        }
        return max_sum/double(k);
    }
};

int main()
{
    Solution sol;

    vector<int> s = {5};
    int k = 1;
    cout<<sol.findMaxAverage(s, k)<<endl;
    
    return 0;
}