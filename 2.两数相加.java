/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode index1 = l1,index2 = l2;
        ListNode head = result;
        int index = 0;
        while(index1 != null || index2 != null){
            int x = (index1 != null) ? index1.val : 0;
            int y = (index2 != null) ? index2.val : 0;
            int flag = (x + y + index);
            index = flag / 10;
            head.next = new ListNode(flag % 10);
            head = head.next;
            if(index1 != null){
                index1 = index1.next;
            }
            if(index2 != null){
                index2 = index2.next;
            }
        }
        if(index > 0){
            head.next = new ListNode(index);
        }
        return result.next;
    }
}
// @lc code=end

