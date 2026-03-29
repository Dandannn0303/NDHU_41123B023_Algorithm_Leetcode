
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        return head;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode *prev=nullptr;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            prev=slow;//找slow的點 
            slow=slow->next;//一次跨一個
            fast=fast->next->next;//一次跨兩個
        }
        prev->next=nullptr;//加了一條NULL進去代表中點
        ListNode *left=sortList(head);//是從head開始排序排到prev指的NULL
        ListNode *right=sortList(slow);
        return merge(left,right);
    }
    ListNode* merge(ListNode* a,ListNode* b)
    {
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(a!=nullptr&&b!=nullptr)
        {
            if(a->val<=b->val)
            {
            cur->next=a;
            a=a->next;
            }else
            {
                cur->next=b;
                b=b->next;
            }
           cur=cur->next;
        }
        if(a==nullptr)
        {
            cur->next=b;
        }
        else
        {
            cur->next=a;
        }
        cur->next;
        return dummy->next;
    }
};