#include <vector>
#include <iostream>
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* cur=head;
        ListNode* temp=nullptr;
        ListNode* prev=nullptr;
        while(cur!=nullptr && cur->next!=nullptr)
        {
            if(cur->val<=cur->next->val)
            {
                cur=cur->next;
            }
            else
            {
                temp=cur->next;
                cur->next=cur->next->next;
                prev =dummy;
                while(prev->next->val<=temp->val)
                {
                    prev=prev->next;
                }
                temp->next=prev->next;
                prev->next=temp;
            }
        }
    return dummy->next;
    }
};