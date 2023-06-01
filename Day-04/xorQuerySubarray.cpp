// Problem of LeetCode
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& query) {
        vector<int> cumilativeXOR; int Xor=0;
        for(int i=0; i<arr.size(); i++){
            Xor=Xor^arr[i];
            cumilativeXOR.push_back(Xor);
        }
        
        vector<int> ans;
        for(int i=0; i<query.size(); i++){
            int start=query[i][0];
            int end=query[i][1];
            if(start==0){
                ans.push_back(cumilativeXOR[end]);
            }
            else{
                int temp=cumilativeXOR[end]^cumilativeXOR[start-1];
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)