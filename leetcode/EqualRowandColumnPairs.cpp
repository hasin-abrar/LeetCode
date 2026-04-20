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
    template<typename T>
    void print_vec(vector<T>& vec, int n = 0){
        if(!n) n = vec.size();
        for(size_t i=0; i<n; i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    void inc_matched_if_valid(vector<vector<int>>& grid, int r, int c, int& match){
        bool matched = true;
        for(int i=0; i<grid.size(); i++){
            if(grid[r][i] != grid[i][c]){
                matched = false;
                break;
            }
        }
        if(matched) match++;
    }

    int equalPairs(vector<vector<int>>& grid) {
        vector<int32_t> rows, cols;
        const int limit = 10001;
        for(auto vec: grid){
            int encoding = 0;
            for(auto val: vec){
                encoding += val;
            }
            rows.emplace_back(encoding);
        }
        for(int i=0; i<grid.size(); i++){
            int encoding = 0;
            for(int j=0; j<grid.size(); j++){
                encoding += grid[j][i];
            }
            cols.emplace_back(encoding);
        }

        // print_vec(rows);
        // print_vec(cols);

        int match = 0;
        for(int i=0; i<rows.size(); i++){
            for(int j=0; j<cols.size(); j++){
                if(rows[i] == cols[j]) inc_matched_if_valid(grid, i, j, match);
            }
        }
        return match;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> s = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout<< sol.equalPairs(s)<<endl;

    
    return 0;
}