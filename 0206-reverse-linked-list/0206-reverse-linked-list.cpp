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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* ptr = head->next;
        head->next = nullptr;
        while(ptr!=nullptr) {
            ListNode* temp = ptr->next;
            ptr->next = head;
            head = ptr;
            ptr = temp;
        }
        return head;
    }
};