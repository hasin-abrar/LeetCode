#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


class RecentCounter {
public:
    queue<int> Q;
    RecentCounter() {
        std::queue<int> emptyQueue;
        Q.swap(emptyQueue); 
    }
    
    int ping(int t) {
        Q.push(t);
        int max_top = max(0, t-3000);
        while(!Q.empty()){
            int top = Q.front();
            if(top < max_top) Q.pop();
            else break;
        }
        return Q.size();
    }
};




int main(){
    RecentCounter* obj = new RecentCounter();
    vector<int> ping_times = {-1, 1, 100, 3001, 3002};
    for(auto ping: ping_times){
        if (ping == -1) obj = new RecentCounter();
        else std::cout<<obj->ping(ping)<<std::endl;
    }
    return 0;
}