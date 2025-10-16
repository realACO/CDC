struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* len=head;
        int length=0;
        while(len){
            length++;
            len=len->next;
        }
        //finding the length of linked list
        if(head==nullptr||head->next==nullptr||k%length==0)return head;
        //edge cases

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* fast=dummy;


        k=k%length;
        //rotationg a linked list of length 5 by 2 position or 7 position will yield the same output
        while(k--){
            fast=fast->next;
        }
        //iterate this pointer k positions

        ListNode* slow=dummy;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        //iterate both fast and slow til any one of them reaches nullptr
        //ex
        //fast
        //dummy       1    2    3    4    5      k==3, len==5

        //                     fast
        //dummy       1    2    3    4    5      k==3, len==5
        
        //slow                 fast
        //dummy       1    2    3    4    5      k==3, len==5
        
        //iterate together till next of any one reaches nullptr
        //                slow           fast
        //dummy       1    2    3    4    5      k==3, len==5

        //now just point the next of fast to null
        //store next of slow as answer
        //point slow next to nullptr

        //            3    4    5    1    2 ANSWER
        ListNode* realHead=slow->next;
        slow->next=nullptr;
        fast->next=head;
        head=realHead;
        return head;


    }
};