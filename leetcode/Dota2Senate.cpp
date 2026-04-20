#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    template<typename T>
    void print_queue(queue<T> Q){
        while(!Q.empty()){
            cout<<Q.front()<<" ";
            Q.pop();
        }
        cout<<endl;
    }

    string predictPartyVictory(string senate) {
        queue<char> Q, next_round_Q, empty_Q;
        while(1){
            Q.push(senate[0]);
            for(int i=1; i<senate.size(); i++){
                char party = senate[i];
                if(!Q.empty()){
                    char top = Q.front();
                    if(top == party){
                        Q.push(party);
                    }
                    else{
                        Q.pop();
                        next_round_Q.push(top);
                    }
                }
                else{
                    Q.push(party);
                }
            }
            if(next_round_Q.empty()) break;
            int next_round_size = next_round_Q.size();
            while(!Q.empty()){
                int nr_top = next_round_Q.front();
                int q_top = Q.front();
                Q.pop();
                next_round_Q.pop();
                if(q_top != nr_top){
                    next_round_Q.push(q_top);
                }
                else{
                    next_round_Q.push(nr_top);
                    next_round_Q.push(q_top);
                }
                next_round_size--;
                if(next_round_size == 0) break;
            }

            senate = "";
            while(!next_round_Q.empty()){
                senate.push_back(next_round_Q.front());
                next_round_Q.pop();
            }
            while(!Q.empty()){
                senate.push_back(Q.front());
                Q.pop();
            }
        }
        char top = Q.front();
        if(top == 'R') return "Radiant";
        return "Dire";

    }

    // string predictPartyVictory(string senate) {
    //     queue<char> Q, next_round_Q, empty_Q;
    //     int k = 0;
    //     while(1)
    //     {   k++;
    //         cout<<"\nk: "<<k<<endl;
    //         Q.push(senate[0]);
    //         for(int i=1; i<senate.size(); i++){
    //             char party = senate[i];
    //             if(!Q.empty()){
    //                 char top = Q.front();
    //                 if(top == party){
    //                     Q.push(party);
    //                     if(!next_round_Q.empty()) next_round_Q.pop();
    //                 }
    //                 else{
    //                     Q.pop();
    //                     next_round_Q.push(top);
    //                 }
    //             }
    //             else{
    //                 if(!next_round_Q.empty()){
    //                     char nr_top = next_round_Q.front();
    //                     if(nr_top != party){
    //                         next_round_Q.pop();
    //                         next_round_Q.push(party);
    //                     }
    //                     else Q.push(party);
    //                 }
    //                 else Q.push(party);
    //             }
    //             cout<<i<<": Q: ";
    //             print_queue(Q);
    //             cout<<"NRQ: ";
    //             print_queue(next_round_Q);
    //             cout<<endl;
    //         }
    //         if(next_round_Q.empty()) break;
    //         senate = "";
    //         while(!next_round_Q.empty()){
    //             senate.push_back(next_round_Q.front());
    //             next_round_Q.pop();
    //         }
    //         while(!Q.empty()){
    //             senate.push_back(Q.front());
    //             Q.pop();
    //         }
    //     }
    //     char top = Q.front();
    //     if(top == 'R') return "Radiant";
    //     return "Dire";

    // }
};



int main(){
    Solution sol;
    string vote = "DRRDRDRDRDDRDRDRD";
    cout<<sol.predictPartyVictory(vote)<<endl;
    
    return 0;
}

