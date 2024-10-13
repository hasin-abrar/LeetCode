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
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int pos1 = 0, pos2 = nums.size()-1;
        int _count = 0;
        while(1){
            if(pos1 >= pos2) break;
            int diff = k - nums[pos2];
            if(diff < 0){
                pos2--;
                continue;
            }
            if(diff == nums[pos1]){
                pos1++;
                pos2--;
                _count++;
            }
            else if(diff < nums[pos1]){
                pos2--;
            }
            else pos1++;
        }
        return _count;
    }
};

int main()
{
    Solution sol;

    vector<int> s = {1,2,3,4};
    int k = 5;
    cout<<sol.maxOperations(s, k)<<endl;
    
    return 0;
}