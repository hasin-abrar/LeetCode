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
    int largestAltitude(vector<int>& gain) {
        int curr_alt = 0, max_alt = 0;
        for(auto height : gain){
            curr_alt += height;
            max_alt = max(max_alt, curr_alt);
        }
        return max_alt;
    }
};

int main()
{
    Solution sol;

    vector<int> s = {-5,1,5,0,-7};
    cout<<sol.largestAltitude(s)<<endl;
    
    return 0;
}