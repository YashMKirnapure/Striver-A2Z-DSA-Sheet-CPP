#include <iostream>
using namespace std;

Node * merge(Node * list1,Node * list2)
    {
        Node * dummyNode = new Node(-1);
        Node * res = dummyNode;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->data < list2->data)
            {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else
            {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }
        if(list1!=NULL)
            res->bottom = list1;
        else
            res->bottom = list2;
        if(dummyNode->bottom!=NULL)
            dummyNode->bottom->next = NULL;
        return dummyNode->bottom;
    }
  
    Node * flatten(Node * head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        Node * mergedHead = flatten(head->next);
        head = merge(head,mergedHead);
        return head;
    }