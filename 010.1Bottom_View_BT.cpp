class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root){
            return ans;
        }
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* p=it.first;
            int line=it.second;
            mp[line]=p->data;
            if(p->left){
                q.push({p->left,line-1});
            }
            if(p->right){
                q.push({p->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};