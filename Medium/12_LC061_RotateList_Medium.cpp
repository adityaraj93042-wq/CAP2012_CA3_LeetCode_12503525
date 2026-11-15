class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* temp = head;
        int len = 1;

        // Find length and last node
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        // Make k smaller than length
        k = k % len;

        if (k == 0) {
            return head;
        }

        // Connect last node to head
        temp->next = head;

        // Find new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Set new head
        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;  
    }
};