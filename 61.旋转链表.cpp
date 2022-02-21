/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* index = head;
        if(head == nullptr || k == 0)return head;
        int length = 1;
        while(index->next != nullptr){
            length++;//记录链表长度
            index = index->next;
        }
        int tmp = (k % length);
        if(tmp == 0)return head;
        index = head;
        while(tmp < length){
            index = index->next;
            tmp++;
        }
        ListNode* ans = index;
        while(index->next != nullptr){
            index = index->next;
        }
        index->next = head;
        while(head->next != ans){
            head = head->next;
        }
        head->next = nullptr;
        return ans;
    }
};
// @lc code=end

