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
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* ptr = head;
    while(ptr != nullptr) {
        ListNode* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr) {
            fast = fast -> next;
            if(fast != nullptr) {
                slow = slow -> next;
                fast = fast -> next;
            }
        }
        ListNode* rev = reverse(slow);
        while(rev != nullptr && head != nullptr) {
            if(head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};