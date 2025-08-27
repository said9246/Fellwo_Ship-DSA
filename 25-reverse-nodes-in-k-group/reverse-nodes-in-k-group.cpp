class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Check if there are at least k nodes remaining
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head; // Less than k nodes, no reversal

        // Reverse k nodes
        curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Recurse on the remaining list
        head->next = reverseKGroup(curr, k);

        return prev; // prev is new head of the reversed group
    }
};
