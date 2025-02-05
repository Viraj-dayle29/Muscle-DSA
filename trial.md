# LeetCode Problem 24 - Swap Nodes in Pairs

## Problem Details
| Problem No. | Problem Link |
|------------|-------------|
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) |

## Solution (Python)
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapPairs(head: ListNode) -> ListNode:
    if not head or not head.next:
        return head
    
    new_head = head.next
    prev = None
    
    while head and head.next:
        first = head
        second = head.next
        
        first.next = second.next
        second.next = first
        
        if prev:
            prev.next = second
        prev = first
        head = first.next
    
    return new_head
