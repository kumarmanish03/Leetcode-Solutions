// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/contest/weekly-contest-179/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int ans = INT_MIN;
    
    void dfs(int u, vector<vector<int> > &adj, int sum, vector<int>& time){
        
        if(adj[u].size() == 0){
            if(ans < sum)
                ans = sum;
            return;
        }
        sum += time[u];
        for(auto v:adj[u]){
            dfs(v, adj, sum, time);
        }
        sum -= time[u];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& time) {
        if(n < 2) return 0;
        vector<vector<int> > adj(n);
        for(int i = 0; i < man.size(); i++){
            if(man[i] == -1) continue;
            adj[man[i]].push_back(i);
        }
        dfs(headID, adj, 0, time);
        return ans;
    }
};