## Floyd's cycle :
### MIDDLE NODE :
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

### DETECT CYCLE AND ENTRY POINT OF CYCLE:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool cycle = false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                cycle=true; break ;
            }
        }
        if(!cycle) return nullptr;
        // slow to entry point == head to entry point.
        while(slow!=head){
            slow=slow->next; head=head->next;
        }

        return slow;
    }
};

