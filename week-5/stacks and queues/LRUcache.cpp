class LRUCache {
public:
    class node{
        public:
        int val;
        int key;
        node* next;
        node* prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void addnode(node *newnode)
    {
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node *delnode)
    {
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
        node* resnode=mp[key];
        int res=resnode->val;
        deletenode(resnode);
        addnode(resnode);
        return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node *existingNode = mp[key];
            mp.erase(key);
            deletenode(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
        
    }
};
