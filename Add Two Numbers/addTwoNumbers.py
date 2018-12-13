# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        """
        思路是和c++实现方法相同，所以这里不多做注释，结果并不是很理想，py50% cpp40%
        """
        divide_value = 0
        first = l1
        second = l2
        is2 = 0
        while True:
        	sum = l1.val + l2.val +divide_value
        	residual_value = sum % 10
        	l1.val = residual_value
        	l2.val = residual_value
        	divide_value = int(sum / 10) # 这里和cpp不同的是，cpp除法的结果根据变量而定，这里都是int，返回也是int 但是py会变成浮点型，所以强制转换一下
        	if l1.next and l2.next:
        		l1 = l1.next
        		l2 = l2.next
        	elif l1.next is not None and l2.next:
        		l2.val = 0
        		l1 = l1.next
        	elif l1.next and l2.next is not None:
        		l1.val = 0
        		l2 = l2.next
        		is2 = 1
        	else:
        		if is2:
        			if divide_value != 0:
        				l2.next = ListNode(divide_value)
        				return second
        			return second
        		else:
        			if divide_value != 0:
        				l1.next = ListNode(divide_value)
        				return first
        			return first
        			