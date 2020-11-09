/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
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
        ListNode index = head;
        int sum = 0;
        while(index.next != null){
            sum++;
            index = index.next;
        }
        sum++;//5
        if(sum == n){
            head = head.next;
            return head;
        }

        int i = 0;
        ListNode left = head;
        index = head;
        while(i < sum - n){
            index = index.next;
            if(i > 0){
                left = left.next;
            }
            i++;
        }
        if(index.next == null){
            left.next = null;
            return head;
        }
        left.next = index.next;
        return head;
    }
}
// @lc code=end

