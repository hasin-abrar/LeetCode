#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int pos1 = 0, pos2 = height.size()-1;
        int curr_area, max_area = 0;
        while (1)
        {
            if(pos1 == pos2) break;
            curr_area = min(height[pos1], height[pos2])*(pos2-pos1);
            if(curr_area > max_area) max_area = curr_area;
            if(height[pos1] < height[pos2]) pos1++;
            else pos2--;
        }
        return max_area;
    }

};


int main()
{
    Solution sol;

    vector<int> s = {0,0};
    cout<<sol.maxArea(s)<<endl;
    
    return 0;
}