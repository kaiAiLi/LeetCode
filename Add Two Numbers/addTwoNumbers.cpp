/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
/**
整体思路，不开辟新的链表来存结果，而是在原有链表的基础上进行重新赋值，如果长度不够，
才会开辟新的链表来增加长度。while循环链表，将两个数相加，除10并取余10.得到个数位和十位数的值
sum = 两个链表的值(或者单个链表的值，当两个链表长度不相等时) + 除10得到的值做为新的结果
并且做除法和取余操作。进行下次计算。当到结尾时，我们在之前就使用if (l1->next == NULL)语句来提前结束循环。因为发现在尾部添加新的链表时，如果l1 == NULL，则无法添加。必须l1->next == NULL时，将l1指向新的结点才能添加。
*/
        int sum = 0;
        int divide_value = 0;
        int residual_value = 0;
        auto first = l2;
        auto second = l1;
        
        while (true) {
            sum = l1->val + l2->val + divide_value;
            residual_value = sum % 10;
            l2->val = residual_value;
            l1->val = residual_value;
            divide_value = sum / 10;
            if (l1->next == NULL or l2->next == NULL)
                break;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        if(l2->next == NULL and l1->next != NULL) {
            l1 = l1->next;
            while(l1) {
                sum = l1->val + divide_value;
                residual_value = sum % 10;
                l1->val = residual_value;
                divide_value = sum / 10;
                if (l1->next == NULL) {
                    break;
                }
                l1 = l1->next;
            }
            if (divide_value != 0) {
                ListNode *p = new ListNode(divide_value);
                l1->next = p;
                l1 = l1->next;
            }
            return second;
            
        }
        else if(l1->next == NULL and l2->next != NULL) {
            l2 = l2->next;
            while(l2) {
                sum = l2->val + divide_value;
                residual_value = sum % 10;
                l2->val = residual_value;
                divide_value = sum / 10;
                if (l2->next == NULL) {
                    break;
                }
                l2 = l2->next;
            }
            if (divide_value != 0) {
                ListNode *p = new ListNode(divide_value);
                l2->next = p;
                l2 = l2->next;
            }
            return first;
        }
        else {
            if (divide_value != 0) {
                ListNode *p = new ListNode(divide_value);
                l2->next = p;
                l2 = l2->next;
            }
            return first;
        }
        
    }
};