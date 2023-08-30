/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
 public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nBehindPrev = new ListNode(0);
        nBehindPrev.next = head;
        ListNode nBehind = head;

        ListNode headPrev = nBehindPrev;
        headPrev.next = head;

        ListNode current = head;

        int count = 0;
        while (current != null){
            if (count >= n){
                nBehindPrev =  nBehindPrev.next;
                nBehind  = nBehind.next;
            }

            current = current.next;
            count++;
        }

        nBehindPrev.next = nBehind.next;

        return headPrev.next;
    }
}