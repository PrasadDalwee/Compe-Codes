#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(head1, head2):
    
    n1,n2=head1,head2
    print(n1.data,n2.data)
    if(head1.data<=head2.data):
        head, node, n1 = head1, head1, head1.next
    
    else:
        head, node, n2 = head2, head2, head2.next
        
    while n1!=None and n2!=None:
        print(n1.data,n2.data)
        if n1.data<=n2.data:
            node.next, n1 = n1, n1.next
            node=node.next
        
        else:
            node.next, n2 = n2, n2.next
            node=node.next
            
    while n1!=None:
        print(n1.data)
        node.next=n1
        node=n1
        n1=n1.next
        
    while n2!=None:
        print(n2.data)
        node.next=n2
        node=n2
        n2=n2.next
        
    return head
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tests = int(input())

    for tests_itr in range(tests):
        llist1_count = int(input())

        llist1 = SinglyLinkedList()

        for _ in range(llist1_count):
            llist1_item = int(input())
            llist1.insert_node(llist1_item)
            
        llist2_count = int(input())

        llist2 = SinglyLinkedList()

        for _ in range(llist2_count):
            llist2_item = int(input())
            llist2.insert_node(llist2_item)

        llist3 = mergeLists(llist1.head, llist2.head)

        print_singly_linked_list(llist3, ' ', fptr)
        fptr.write('\n')

    fptr.close()
