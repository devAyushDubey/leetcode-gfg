/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteMiddle = function(head) {
    if(head.next == null) return null;
    if(head.next.next == null) {
        head.next = null;
        return head;
    }
    let fast = head;
    let slow = head;
    while(fast!=null) {
        fast = fast.next;
        if(fast!=null) {
            fast = fast.next;
            slow = slow.next;
        }
    }
    slow.val = slow.next.val;
    slow.next = slow.next.next;
    return head;
};