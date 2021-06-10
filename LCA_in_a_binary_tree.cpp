
class Solution
{
    
    
    
    public:
    
    bool utility(Node * root, int n, vector<Node *> &v){
        
        if(root==nullptr) return false;
        
           v.push_back(root);
        
        if(root->data==n){
            return true;
        }
        
     
        
        if((root->left && utility(root->left,n,v))||(root->right && utility(root->right,n,v))){
            
            return true;
        }
        v.pop_back();
        return false;
        
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==nullptr) return nullptr;
       
         vector<Node *> v1;
        vector<Node *> v2;
        bool ans1=utility(root, n1 , v1);
        bool ans2=utility(root,n2,v2);
        
        if(ans1 ^ ans2 ==1) return false;
        
        unordered_set<Node *> s;
        for(auto x:v1){
            s.insert(x);
        }
        Node * ans=nullptr;
        for(auto x:v2){
            
            if(s.find(x)!=s.end()){
                ans=x;
            }
        }
        return ans;
        
    }
};