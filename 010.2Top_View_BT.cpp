class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(!root){
            return ans;
        }
        
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* p=it.first;
            int line=it.second;
            mp[line].push_back(p->data);
            if(p->left){
                q.push({p->left,line-1});
            }
            if(p->right){
                q.push({p->right,line+1});
            }
        }
        for(auto it:mp){
            vector<int>v=it.second;
            ans.push_back(v[0]);
        }
        return ans;
    }

};