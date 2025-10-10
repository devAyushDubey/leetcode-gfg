/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let ptr = head;
    let target = head;
    let distance = 0;
    while(ptr != null) {
        ptr = ptr.next;
        if(distance == n + 1) {
            target = target.next;
        }
        else {
            distance++;
        }
    }
    if(distance != n + 1) {
        return head.next;
    }
    if(!target.next) return null;
    target.next = target.next.next;
    return head;
};