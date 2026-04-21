#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int get_right_max(vector<int>& vec){
    vector<bool> flag(vec.size());
    int curr_max = vec[0];
    for(size_t i=0; i<vec.size(); i++){
        if(vec[i] >= curr_max) {
            flag[i] = true;
            curr_max = vec[i];
        }
        else flag[i] = false;
    }
    int count = 0;
    for(auto f: flag){
        if(f == true) count++;
    }
    return count;
}

int main(){
    int c;
    cin >> c;

    while(c--){
        int n;
        cin>>n;
        vector<int> vec;
        vec.reserve(n);
        while (n--)
        {
            int val;
            cin >> val;
            vec.push_back(val);
        }
        cout<<get_right_max(vec)<<"\n";
    }

    return 0;
}