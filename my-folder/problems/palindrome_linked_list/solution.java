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
  public boolean isPalindrome(ListNode head) {
        if (head == null){
            return false;
        }

        ListNode slowPrev = new ListNode(0);
        ListNode slow=  head;
        ListNode fast = head;

        while (fast  != null && fast.next != null){
            fast =  fast.next.next;
            slowPrev=  slow;
            slow= slow.next;
        }

        slowPrev.next=  null;
        ListNode reversed2NdHalf=  reverseLinkedList(slow);
        ListNode l1 = head ;
        ListNode l2 = reversed2NdHalf;

        while (l1 != null && l2 != null){
            if (l1.val != l2.val){
                return false;
            }

            l1 = l1.next;
            l2 = l2.next;
        }

        return true;
    }
    public ListNode reverseLinkedList(ListNode head){
        ListNode prev=  null;
        ListNode curr = head;
        while (curr != null){
            ListNode nextTemp  = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}