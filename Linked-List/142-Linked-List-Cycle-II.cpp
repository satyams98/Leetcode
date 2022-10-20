/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //tortoise and hare
        
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow){
                fast = head;
                
                while(fast!=slow){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return fast;
            }
                
        }
        
        return NULL;
        
        
    }
};
