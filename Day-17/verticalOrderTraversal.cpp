//                      LEETCODE SOLUTION [ VERY VERY IMPORTANT ]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class util{
    public:
    TreeNode* root;
    int vertical;
    int level;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>> ans; return ans;
        }
        // we will use level order traversal to iterate over all the node
        queue<util*> q;
        util* t= new util(); (*t).root=root; (*t).vertical=0; (*t).level=0; q.push(t);
        // storing { root node, its level and vertical } in queue with help of util class
    
        map<int, map<int, multiset<int>>> m; // [vertical] --> [level] --> {set of all node at (vertical,level)}
        // as this is a map, so vertical will be sorted (key of first map)
        // level will be sorted (key of nested map), and nodes at (vertical,level) too will be soted (stored in multiset)
        
        while(!q.empty()){
            util* t= q.front(); q.pop();
            TreeNode* front=(*t).root; int vertical=(*t).vertical; int level=(*t).level;
            
            m[vertical][level].insert((*front).val);
            
            if((*front).left != NULL){
                util* utl=new util();
                (*utl).root=(*front).left; (*utl).level=level+1; (*utl).vertical=vertical-1;
                q.push(utl);
            }
            if((*front).right != NULL){
                util* utl=new util();
                (*utl).root=(*front).right; (*utl).level=level+1; (*utl).vertical=vertical+1;
                q.push(utl);
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto it= m.begin(); it != m.end(); it++){
            vector<int> vec;
            // (*it).second is a map : map at different level. Each level has set too
            
            for(auto itr=(*it).second.begin(); itr!=(*it).second.end(); itr++){
                //vec.insert(vec.end(), (*itr).second.begin(), (*itr).second.end());
                for(auto itrr=(*itr).second.begin(); itrr!=(*itr).second.end(); itrr++){
                    vec.push_back((*itrr));
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

