struct Node{
    int val;
    Node* next;
    Node(int x):val(x), next(NULL){}

};

class MyLinkedList {
public:
    Node* head;
    
    MyLinkedList() {
         head=NULL;
        
    }
    
    int get(int index) {
        if(index<0 || this->head==NULL)
            return -1;
        
       
        Node* ptr = this->head;
        
        while(index){
            if(ptr->next==NULL && index!=0)
                return -1;
            
            ptr = ptr->next;
            index--;
        }
        
        return ptr->val;
        
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        
    }
    
    void addAtTail(int val) {
        Node* ptr = this->head;
        Node* newNode = new Node(val);
        
        if(ptr==NULL){
            this->head = newNode;
            return;
        }
    
        while(ptr->next!=NULL)
            ptr = ptr->next;
        
        
        ptr->next = newNode;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 ||(index>0 && this->head==NULL))
            return;
        
        
        Node* ptr = this->head;
      
        
        if(index==0){
            addAtHead(val);
            return;
        }
        
        index--;
        
        while(index){
            if(ptr->next==NULL && index!=0)
                return;
            ptr=ptr->next;
            index--;
        }
        
        Node* newNode = new Node(val);
        newNode->next = ptr->next;
        ptr->next = newNode; 
        
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0 ||(index>0 && this->head==NULL))
            return;
        
        Node* toDelete=NULL;
        
        Node* ptr = this->head;
        
        if(index==0){
            toDelete = this->head;
            
            this->head = this->head->next;
            delete toDelete;
            return;
            
        }
        
        index--;
        
        while(index){
            if(ptr->next==NULL && index!=0)
                return;
            ptr=ptr->next;
            index--;
        }
        
        toDelete = ptr->next;
        if(toDelete==NULL)  return;
        
        ptr->next = ptr->next->next;
        delete toDelete;
        return;
        
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
