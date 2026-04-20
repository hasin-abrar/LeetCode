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


    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev_prev = head, *prev = head;
        head = head->next;
        prev->next = nullptr;
        prev = head;
        while (head != nullptr && head->next != nullptr)
        {
            // cout<<head->val<<"\n";
            head = head->next;
            prev->next = prev_prev;
            prev_prev = prev;
            prev = head;
        }
        // cout<<prev->val<<"\n";
        prev->next = prev_prev;
        return prev;
    }
};
 

int main(){
    Solution sol;
    vector<int> values = {1, 2};

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
    ListNode* res_head = sol.reverseList(head);
    sol.print(res_head);

    return 0;
}