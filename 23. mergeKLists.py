from queue import PriorityQueue


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def mergeKLists(lists):
    k = len(lists)
    q = PriorityQueue(maxsize=k)
    dummy = ListNode(None)
    curr = dummy
    for list_idx, node in enumerate(lists):
        if node: q.put((node.val, list_idx, node))
    while q.qsize() > 0:
        popped = q.get()
        curr.next, list_idx = popped[2], popped[1]
        curr = curr.next
        if curr.next: q.put((curr.next.val, list_idx, curr.next))
    return dummy.next


if __name__ == '__main__':
    # a = [ListNode(1), ListNode(4), ListNode(5)]
    # b = [ListNode(1), ListNode(3), ListNode(4)]
    # c = [ListNode(2), ListNode(6)]
    a = ListNode(1)
    b = ListNode(4)
    a.next = b
    c = ListNode(5)
    b.next = c

    d = ListNode(1)
    e = ListNode(3)
    d.next = e
    f = ListNode(4)
    e.next = f

    g = ListNode(2)
    h = ListNode(6)
    g.next = h

   j = mergeKLists([a, d, g])

   while j.next != None:
       print(j.val)
