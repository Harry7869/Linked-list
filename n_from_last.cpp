int getNthFromLast(Node *head, int n)
{
    Node*p=head;
    Node*f=head;
    for(int i=0;i<n-1;i++)
    {
        f=f->next;
        if(f==NULL)
        return -1;
    }
    while(f->next!=NULL)
    {
        p=p->next;
        f=f->next;
    }
    return p->data;
}

// Time - O(n)
// Space - O(1)