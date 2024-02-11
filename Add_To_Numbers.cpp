/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 2->4->3
 5->6->4
 -------
 7->0->8

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

// -------------------------------------------------------------------------------SOLUTION---------------------------------------------------------------------------------


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
    void insert_at_end(ListNode* head ,int key)
    {
        ListNode * ptr = head ; 
        while(ptr->next)
        ptr = ptr->next ; 
        
        ListNode *temp = new ListNode(key)  ;
        temp->next = NULL ; 
        ptr->next = temp ;
    }
    ListNode* reverse(ListNode *head) 
    {
        ListNode *prev = NULL ,*curr = head ; 
        while(curr)
        {
            ListNode* nex = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nex ;
        }
        return prev ;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second)
    {
        ListNode* ptr1 = first ,* ptr2 = second ;
        int carry = 0;
        ListNode *ans = new ListNode(-1) ; 
        // Node* prev1 = NULL ,*prev2 = NULL;
        while(ptr1 && ptr2)
        {
            // prev1 = ptr1;
            // prev2 = ptr2; 
            if(ptr1->val + ptr2->val + carry >= 10)
            {
                insert_at_end(ans,(ptr1->val + ptr2->val + carry)%10 ) ;
                carry = 1; 
            }
            else 
            {
                insert_at_end(ans,(ptr1->val + ptr2->val + carry)%10 ) ;
                carry = 0 ;
            }
            ptr1 = ptr1->next ;
            ptr2 = ptr2->next ;
        }
        if(ptr1 == NULL)
        {
            while(ptr2)
            {
                insert_at_end(ans,(ptr2->val + carry) %10 ) ; 
                if(ptr2->val + carry >= 10)
                carry = 1 ;
                else 
                carry = 0 ;
                ptr2 = ptr2->next ; 
            }
        }
        else 
        {
            while(ptr1)
            {
                insert_at_end(ans,(ptr1->val + carry) %10 ) ; 
                if(ptr1->val + carry >= 10)
                carry = 1 ;
                else 
                carry = 0 ;
                ptr1 = ptr1->next ; 
            }
        }
        if(carry)
        insert_at_end(ans,carry) ; 
        //ans = reverse(ans->next) ; 
    
        return ans->next  ;// code here
    }
};