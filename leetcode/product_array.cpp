/**
 * 238. Product of Array Except Self
 */
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    void product(vector<int32_t>& A, int32_t i, int32_t j){
        int32_t n = j - i + 1;
    
        if(n == 2){
            swap(A[i], A[j]);
            return;
        }
        if(n == 3){
            int32_t x = A[i+1] * A[i+2];
            int32_t y = A[i] * A[i+2];
            int32_t z = A[i] * A[i+1];   
            A[i] = x;
            A[i+1] = y;
            A[i+2] = z;
            return;
        }
        int32_t m = i + ceil(n/2.0);
        
        int32_t pref = 1, suf = 1;
        for(int32_t d=i; d<=j; d++){
            if(d<m){
                pref *= A[d];
            }
            else{
                suf *= A[d];
            }
        }
        product(A, i, m-1);
        product(A, m, j);
        for(int32_t d=i; d<=j; d++){
            if(d<m){
                A[d] *= suf;
            }
            else{
                A[d] *= pref;
            }
        }
    }

    vector<int32_t> productExceptSelf(vector<int32_t>& nums) {
        product(nums, 0, nums.size()-1);
        return nums;
    }
};

int main(){

    Solution sol;

    vector<int32_t> nums = {5,9,2,-9,-9,-7,-8,7,-9,10};
    // vector<int32_t> nums = {-1,1,0,-3,3, -1,1,0,-3,3};
    vector<int32_t> res =sol.productExceptSelf(nums);

    for(int32_t i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}