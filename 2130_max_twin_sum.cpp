#include "headers.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}


};

class Solution {
public:

    void print(ListNode* head){
        while(head != nullptr){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<"\n";
    }
    int get_count(ListNode* head){
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }

    int pairSum(ListNode* head) {
        // int count = get_count(head);
        vector<int> value_vec;
        value_vec.push_back(head->val);
        ListNode *fast = (head->next)->next, *slow = head->next;
        while(fast != nullptr){
            value_vec.push_back(slow->val);
            slow = slow->next;
            fast = (fast->next)->next;
        }
        // int mid = count / 2;
        // value_vec.reserve(mid + 1);
        // while(head != nullptr){
        //     value_vec.emplace_back(head->val);
        //     head = head->next;
        //     if(value_vec.size() == mid) break;
        // }
        // cout<<value_vec.size()<<endl;
        head = slow;
        int max_sum = 0;
        for(int i=value_vec.size()-1; i>=0; i--){
            int sum = value_vec[i] + head->val;
            if(sum > max_sum) max_sum = sum;
            head = head->next;
        }
        return max_sum;
    }
};

int main(){
    Solution sol;
    vector<int> values = {7,4};

    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    for(int i=0; i<values.size(); i++){
        ListNode* ln = new ListNode(values[i]);
        if(i > 0){
            prev->next = ln;
        }
        else{
            head = ln;
        }
        prev = ln;
    }

    
    sol.print(head);
    cout<< sol.pairSum(head)<<endl;
    

    return 0;
}