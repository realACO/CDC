class MyLinkedList {
public:
    int val;
    MyLinkedList* next;
    MyLinkedList* tail;
    int size;
    //we will use this as a head pointer in allcase
    //this isa a dumy node and this->next is where the list begins, or the head of the ll
    MyLinkedList() {
        val=0;
        next=nullptr;
        size=0;
        tail=this;
        //we will also maintain a tail for easier access at end of tail operations
    }

    int get(int index) {
        if(index<0||index>=size)return -1;
        //invalid index so we return -1
        MyLinkedList* temp=this->next;
        //intialize temp with the head od ll
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        //iterate index times to reach the needed node
        return temp->val;
        //return its value
    }
    
    void addAtHead(int val) {
        MyLinkedList* nn=new MyLinkedList();
        nn->val=val;
        //create a new node and set its value to val
        nn->next=this->next;
        //set the next pointer of nn to the first node of ll
        this->next=nn;
        //repoint the dummy this pointer to start of ll
        if(size==0)tail=nn;
        //edge case if size is 0 that means no node in ll, also means tail isnt pointing to any node in ll
        size++;
    }
    
    void addAtTail(int val) {
        MyLinkedList* nn=new MyLinkedList();
        nn->val=val;
        //create node the same we did earlier
        if(size==0){
            this->next=nn;
            tail=nn;
            //if size is 0 that means first node of ll, and also initialize thetail with a node of ll
        }else{
            tail->next=nn;
            tail=nn;
            //if size greater than 0 just point tail to the nn and set tail to that nn
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* nn=new MyLinkedList();
        nn->val=val;
        //create node just as before
        if(index<0||index>size)return;
        //invalid index
        MyLinkedList* temp=this;
        //starting from the dummy node this not this->next bcz to add a new node a nth index we want the pointer of n-1 node
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        //move temp index times
        nn->next=temp->next;
        temp->next=nn;
        //inserting the node
        if(nn->next==nullptr)tail=nn;
        //edge case if after inserting the node we are at the last node of ll so we need to update tail
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size)return;
        //invalid indes
        MyLinkedList* temp=this;
        //start from dummy node as we want pointer of n-1 th node
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        //itertate index times
        MyLinkedList* temp1=temp->next;
        //set temp1 to the next node of n-1 th node 
        temp->next=temp1->next;
        //setting pointer on n-1th node to the next fo tem1 node (deletion logic)
        if(temp1==tail)tail=temp;
        //edge case the node that is being deleted is tail , and if so set tail to temp that is n-1th node
        delete temp1;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */