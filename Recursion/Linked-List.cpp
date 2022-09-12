class Node{
    public:
    int data;
    Node* next;
    
    Node (int data): data(data), next(NULL){}
};

void insertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head=temp;
    
}

void deleteAtPos(Node* &head, int pos){//0th based
          
    Node* ptr = head;
   if(pos==0){
      
       head = head->next;
       delete ptr;
       return ;
   }
    pos--;
    
    while(pos--){
         
        ptr = ptr->next; 
        
        if(ptr->next==NULL){
            cout<<"position geater than no of elements"<<endl;
            return;    
        }
       
    }
    
    
    Node* temp = ptr->next;
   
    ptr->next = ptr->next->next;
    delete temp;
    return;
    
}

void insertInMiddle(Node* &head, int data){
    Node* temp = new Node(data);
    Node* sptr = head;
    Node* fptr = head->next;
    
    while(fptr->next!=NULL && fptr->next->next!=NULL){
        sptr = sptr->next;
        fptr = fptr->next->next;
    }
    
    temp->next=sptr->next;
    sptr->next = temp;
    
}

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<" null"<<endl;
}

int main() {
    Node *head = new Node(7);
  
    printLL(head);
    
    insertAtHead(head, 12);
   
    printLL(head);
    
    insertInMiddle(head, 5);
    
    printLL(head);
    
     insertInMiddle(head, 4);
     printLL(head);
    deleteAtPos(head, 4);
    printLL(head);
    
}
