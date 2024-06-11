class Solution {
public:
    Node* flatten(Node* head) {
        Node*root=head;
        while(head!=NULL)
        {
            if(head->child!=NULL)
            {
                Node*next_node=head->next;
                head->next=head->child;
                head->child->prev=head;
                head->child=NULL;
                Node*p=head->next;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p->next=next_node;
                if(next_node)
                {
                    next_node->prev=p;
                }
            }
            head=head->next;
        }
        return root;
    }
};