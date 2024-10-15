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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = 0, n2 = 0, n1_prev = nums1[0], n2_prev = nums2[0];

        while(1){
            if(n1 == nums1.size()){
                while (n2 < nums2.size())
                {
                    res[1].push_back(nums2[n2]);
                    n2_prev = nums2[n2];
                    while(++n2 < nums2.size() && nums2[n2] == n2_prev);
                }
                break;
            }
            else if(n2 == nums2.size()){
                while (n1 < nums1.size())
                {
                    res[0].push_back(nums1[n1]);
                    n1_prev = nums1[n1];
                    while(++n1 < nums1.size() && nums1[n1] == n1_prev);
                }
                break;
            }
            // compare to see which index to move forward
            if(nums1[n1] < nums2[n2]){
                res[0].push_back(nums1[n1]);
                n1_prev = nums1[n1];
                while(++n1 < nums1.size() && nums1[n1] == n1_prev);
            }
            else if(nums1[n1] > nums2[n2]){
                res[1].push_back(nums2[n2]);
                n2_prev = nums2[n2];
                while(++n2 < nums2.size() && nums2[n2] == n2_prev);
            }
            else{
                n1_prev = nums1[n1];
                n2_prev = nums2[n2];
                while(++n1 < nums1.size() && nums1[n1] == n1_prev);
                while(++n2 < nums2.size() && nums2[n2] == n2_prev);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> s1 = {1,2,3,3};
    vector<int> s2 = {1};
    auto vec = sol.findDifference(s1, s2);

    for(auto arr: vec){
        for(auto val: arr){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}