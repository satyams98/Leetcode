    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return head;
        
       ListNode* temp = head->next;
       head->next=temp->next;
        temp->next=head;
        head = temp;
        
        
        head->next->next= swapPairs(head->next->next);
        return head;
        
        
       
    }