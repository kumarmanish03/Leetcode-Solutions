/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
* @desc: Modified Dijkstra, maintain all states od dijkstra
*
*/

class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, long long>> adj[n];
        for(auto v:roads){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        vector<bool> processed(n, false);
        vector<long long> time(n, LLONG_MAX);
        vector<long long> cnt(n, 0);
        multiset<pair<long long, int>> ms;
        ms.insert({0, 0});
        time[0] = 0LL;
        cnt[0] = 1LL;
        while(!ms.empty()){
            auto [wt, u] = *ms.begin();
            ms.erase(ms.begin());
            
            if(processed[u]) continue;
            
            processed[u] = true;
            
            for(auto [v, wt_v]: adj[u]){
                if(time[v] > time[u] + wt_v){
                    time[v] = time[u] + wt_v;
                    cnt[v] = cnt[u];
                    ms.insert({time[v], v});
                }
                else if(time[v] == time[u] + wt_v){
                    (cnt[v] += cnt[u]) %= mod;
                     ms.insert({time[v], v});
                }
            }
        }
        return cnt[n-1];
    }
};