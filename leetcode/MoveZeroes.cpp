#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

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

void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(size_t i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[pos++] = nums[i];
            }
        }
        for(; pos<nums.size(); pos++){
            nums[pos] = 0;
        }
        // print_vec(nums);
    }
};

int main()
{
    Solution sol;

    vector<int> s = {0};
    sol.moveZeroes(s);
    
    return 0;
}