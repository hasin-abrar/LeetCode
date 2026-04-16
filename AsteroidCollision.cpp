#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>

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

    void print_stack(std::stack<int> s) { // Pass by value to create a copy
    while (!s.empty()) {
        std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << std::endl;
    }

    void unroll_stack(stack<int> &st, int val, int& direction){
        while(!st.empty()){
            int top = st.top();
            if(top < 0) break;
            if(direction == 1){
                if(top > -val) return;
                else if(top == -val){
                    st.pop();
                    return;
                }
            }
            else{
                if(-top > val) return;
                else if(-top == val){
                    st.pop();
                    return;
                }
            }
            st.pop();
        }
        st.push(val);
        direction ^= 1;
    }


    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast_stack;
        int direction;
        vector<int> ans_vec;
        int i = 0;
        int start_index;
        for(; i<asteroids.size(); i++){
            if(asteroids[i] < 0) ans_vec.emplace_back(asteroids[i]);
            else{
                ast_stack.push(asteroids[i]);
                direction = 1;
                start_index = i;
                break;
            }
        }
        if(i == asteroids.size()) return ans_vec;
        for(++i; i<asteroids.size(); i++){
            int curr = asteroids[i];
            if(direction == 1 && curr > 0) ast_stack.push(curr);
            else if(direction == 0) {
                ast_stack.push(curr);
                if(curr > 0) direction ^= 1;
            }
            else{
                unroll_stack(ast_stack, curr, direction);
            }
        }
        i = start_index + ast_stack.size() - 1;
        stack<int> reverse_stack;
        while(!ast_stack.empty()){
            reverse_stack.push(ast_stack.top());
            ast_stack.pop();
        }
        while(!reverse_stack.empty()){
            ans_vec.emplace_back(reverse_stack.top());
            reverse_stack.pop();
        }
        return ans_vec;
    }

};


int main(){
    Solution sol;
    vector<int> s = {1,-2,1,-3};
    vector<int> ans = sol.asteroidCollision(s);
    sol.print_vec(ans);
    return 0;
}