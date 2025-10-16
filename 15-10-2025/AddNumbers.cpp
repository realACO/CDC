struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        //we will add nodes of sums next to ans node and return anw->next

        //intitial carry 0
        int carry=0;
        while(l1!=nullptr||l2!=nullptr){
            int sum=0;
            //if l1 exist add its value to sum
            if(l1!=nullptr){
                sum=sum+l1->val;
                l1=l1->next;
            }
            //if l2 exist add its value to sum
            if(l2!=nullptr){
                sum=sum+l2->val;
                l2=l2->next;
            }
            //basic math
            sum=sum+carry;
            carry=sum/10;

            //make new node with sum mod 10 value, andd point nex t of temp to it
            ListNode* nn=new ListNode(sum%10);
            temp->next=nn;
            temp=temp->next;
        }

        // if carry remains then make new node na dadd it to linked list
        if(carry==1){
            ListNode* nn=new ListNode(1);
            temp->next=nn;
        }
        return ans->next;
    }
};