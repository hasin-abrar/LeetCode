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

    ListNode* deleteMiddle(ListNode* head) {
        int num_elems = get_count(head);
        if(num_elems == 1) return nullptr;
        int mid_elem = num_elems / 2;

        ListNode* true_head = head;
        // print(true_head);

        ListNode* next_elem = head->next;
        int count = 1;
        while(1){
            if(count == mid_elem) break;
            head = head->next;
            next_elem = head->next;
            count++;
        }
        head->next = next_elem->next;

        // print(true_head);

        return true_head;
    }
};

int main(){
    Solution sol;
    vector<int> values = {2,1};

    ListNode* head;
    ListNode* prev;

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

    
    // sol.print(head);
    // sol.print(head);
    sol.deleteMiddle(head);

    return 0;
}