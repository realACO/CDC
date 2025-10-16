
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* dummy=new ListNode();
        dummy->val=-1;
        dummy->next=nullptr;
        ListNode* temp=dummy;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1!=nullptr&&t2!=nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1!=nullptr){
            temp->next=t1;
        }
        if(t2!=nullptr){
            temp->next=t2;
        }
        return dummy->next;
    }
};