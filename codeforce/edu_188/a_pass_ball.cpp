#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int get_count(string &str){
    // int unique_student = 1;
    int curr_student = 1;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'R') curr_student++;
        else break;
        // else curr_student--;
        // if(curr_student > unique_student) unique_student = curr_student;
    }
    // return unique_student;
    return curr_student;
}

int main(){
    int c;
    cin>>c;
    while(c--){
        int n;
        cin >> n;
        string flow_str;
        cin>>flow_str;
        cout<<get_count(flow_str)<<"\n";
    }

    return 0;
}