import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.ListModel;

/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode res = new ListNode();
        if(l1 == null && l2 != null){
            return l2;
        }else if(l1 != null && l2 == null){
            return l1;
        }
        else if(l1 == null && l2 == null){
            return null;
        }
        ListNode head = res;
        ArrayList<Integer> list = new ArrayList<>();
        list.add(l1.val);
        list.add(l2.val);
        int i = 2;
        while(l1.next != null){
            l1 = l1.next;
            list.add(l1.val);
            i++;
        }
        while(l2.next != null){
            l2 = l2.next;
            list.add(l2.val);
            i++;
        }
        list.sort(Comparator.naturalOrder());
        int length = i;
        i = 0;
        while(i < length){
            ListNode index = new ListNode();
            res.val = list.get(i);
            if(i < length - 1){
                res.next = index;
                res = res.next;
                i++;
            }
            else{
                i++;
            }
        }
        return head;
    }
}
// @lc code=end
