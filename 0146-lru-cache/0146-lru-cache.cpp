class LRUCache {
public:
     struct TreeNode
    {
        int key;
        int value;
        TreeNode*next;
        TreeNode*prev;
    };
    unordered_map<int,TreeNode*>mp;
    TreeNode*head;
    TreeNode*tail;
    int n;
    LRUCache(int capacity) {
        n=capacity;
        head=new TreeNode();
        tail=new TreeNode();
        head->next=tail;
        tail->prev=head;
    }
    void add_first(TreeNode*node)
    {
        TreeNode* neb=head->next;
        node->next=neb;
        node->prev=head;
        neb->prev=node;
        head->next=node;
    }
    void del(TreeNode*node)
    {
        TreeNode*prev_node=node->prev;
        TreeNode*next_node=node->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
        node->next=NULL;
        node->prev=NULL;
    }
    void move_to_front(TreeNode*node)
    {
        del(node);
        add_first(node);
    }
    int get(int key)
    {    
        if(mp.find(key)!=mp.end())
        {
            TreeNode*node= mp[key];
            int value=node->value;
            move_to_front(node);
            return value;
        }
        return -1;
    }
    void put(int key, int value) 
    {
        if(mp.find(key)==mp.end())
        {
            TreeNode*node=new TreeNode();
            node->key=key;
            node->value=value;
            if(mp.size()==n)
            {
                TreeNode*LRU=tail->prev;
                mp.erase(LRU->key);
                del(LRU);
            }
            mp[key]=node;
            add_first(node);
        }
        else
        {
            TreeNode*node=mp[key];
            del(node);
            mp.erase(node->key);
            TreeNode*node1=new TreeNode();
            node1->key=key;
            node1->value=value;
            mp[key]=node1;
            add_first(node1);
            // move_to_front(node1);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */