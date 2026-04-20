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

    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* head_even = head, *head_odd = head->next;
        ListNode* true_head_even = head, *true_head_odd = head->next;
        head = head_odd->next;
        head_even->next = nullptr;
        head_odd->next = nullptr;
        int count = 0;
        while (head != nullptr)
        {
            if(count == 0){
                count = 1;
                head_even->next = head;
                head_even = head;
                head = head->next;
                head_even->next = nullptr;
            }
            else{
                count = 0;
                head_odd->next = head;
                head_odd = head;
                head = head->next;
                head_odd->next = nullptr;
            }
        }
        // print(true_head_even);
        // print(true_head_odd);
        head_even->next = true_head_odd;
        return true_head_even;
    }
};

int main(){
    Solution sol;
    vector<int> values = {};

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
    ListNode* res_head = sol.oddEvenList(head);
    sol.print(res_head);

    return 0;
}