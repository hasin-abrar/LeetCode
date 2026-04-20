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
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums){
            sum += n;
        }
        int pref_sum = 0;
        for(int i=0; i<nums.size(); i++){
            int check = sum - nums[i];
            if(pref_sum*2 == check) return i; 
            pref_sum += nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> s = {2,1,-1};
    cout<<sol.pivotIndex(s)<<endl;
    
    return 0;
}