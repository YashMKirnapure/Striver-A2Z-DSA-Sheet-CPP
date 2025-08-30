#include <bits/stdc++.h>
using namespace std;

Node *removeDuplicates(struct Node *head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        Node * temp = head;
        Node * headN = head->next;
        
        while(headN!=NULL)
        {
            if(temp->data != headN->data)
            {
                temp->next = headN;
                headN->prev = temp;
                temp = temp->next;
            }
            headN = headN->next;
        }
        if(temp->next!=NULL)
            temp->next = NULL;
        return head;
    }

 Node *removeDuplicates(struct Node *head) 
    {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        Node * temp = head;
        Node * back = NULL;
        set <int> st;
        
        while(temp!=NULL)
        {
            if(st.find(temp->data) != st.end())
            {
                Node * toDel = temp;
                if(back!=NULL)
                    back->next = temp->next;
                if(temp->next!=NULL)
                    temp->next->prev = back;
                temp = temp->next;
                delete toDel;
            }
            else
            {
                st.insert(temp->data);
                back = temp;
                temp = temp->next;
            }
        }
        return head;
    }
