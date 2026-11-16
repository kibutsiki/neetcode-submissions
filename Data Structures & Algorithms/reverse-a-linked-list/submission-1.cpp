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
        ListNode* reverse = nullptr;
        ListNode* iterator = head;
        
        while(iterator != nullptr){
            ListNode* next = iterator->next;
            iterator->next = reverse;
            reverse = iterator;
            iterator = next;
        }
        
        return reverse;
    }
};