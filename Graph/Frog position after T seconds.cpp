// Manish Kumar, IIIT Allahabad
// Hard

// BFS traversal

https://leetcode.com/contest/weekly-contest-179/problems/frog-position-after-t-seconds/

class Solution {
public:
    int isUnvisited(vector<int> &u, vector<bool> &vis){
        int size = 0;
        for(auto& v:u){
            if(!vis[v])
                size++;
        }
        return size;
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int> > adj(n+1);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<bool>vis(n+1, false);
        queue<pair<int, double>> q;
        q.push({1, 1.0});
        vis[1] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int u = q.front().first;
                double prob = q.front().second;
                q.pop();
                
                int isUnvisit = isUnvisited(adj[u], vis);
                
                if(u == target){
                    if((isUnvisit > 0 && t > 0) || t < 0)
                        return 0;
                    return 1/prob;
                }
                
                for(auto& v:adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push({v, prob * isUnvisit});
                    }
                }
            }
            t--;
        }
        
        return 0;
    }
};