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
void shift(ListNode* correct, ListNode* node) {
    ListNode* temp = node->next;
    node->next = node->next->next;
    temp->next = correct->next;
    correct->next = temp;
}
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* correct = head;
        ListNode* ptr = head -> next;
        while(ptr!=nullptr && ptr->next!=nullptr) {
            ListNode* temp = ptr->next->next;
            shift(correct, ptr);
            correct = correct->next;
            ptr = temp;
        }
        return head;
    }
};