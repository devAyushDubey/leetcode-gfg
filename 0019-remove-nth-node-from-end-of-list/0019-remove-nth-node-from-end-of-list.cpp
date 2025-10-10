/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int total = 0;
        while(ptr != nullptr) {
            ptr = ptr -> next;
            total++;
        }
        if(total == 1) {
            return n == 1 ? nullptr : head;
        }
        ptr = head;
        int curr = 1;
        int target = total - n;
        if(target == 0) {
            return head -> next;
        }
        while(curr < target) {
            ptr = ptr->next;
            curr++;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};