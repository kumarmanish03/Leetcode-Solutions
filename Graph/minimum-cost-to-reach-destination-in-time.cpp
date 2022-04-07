// Manish Kumar, IIIT Allahabad
// Hard

// Dijikstra modified

// This question is similar to standard Dijikstra but here we have to calculate minimum cost (which is assigned to nodes)
// Hence we declare two vectors one for cost[node] and time[node] and apply dijikstra on it
// We choose nextNode if (currCost + nextCityCost <= cost[nextCityNode]) and if not then (currtime + edgeTime <= time[nextNode])
// Also, for multiple edges b/w nodes we choose edge with minimum time

https://leetcode.com/contest/biweekly-contest-56/problems/minimum-cost-to-reach-destination-in-time/

class Solution {
public:
    
int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
    int n = fees.size();
    vector<int> cost(n, INT_MAX);
    vector<int> time(n, INT_MAX);
    
    vector<pair<int, int>> adj[n];
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    // sorting so that for similar nodes minimum time nodes comes first 
    for(int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    // {cost, {time, node}}
    priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({fees[0], {0, 0}});

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        int t = curr.second.first;
        int c = curr.first;
        int u = curr.second.second;

        if(u == n-1)
            return c;
        
        for(int i = 0; i < adj[u].size(); i++){
            auto v = adj[u][i];
            int nextTime = v.second;
            int nextCity = v.first;

            // Ignore node which is already evaluated at it was with less time
            if(i > 0 && adj[u][i-1].first == adj[u][i].first)
                continue;

            if(nextTime + t <= maxTime && c + fees[nextCity] < cost[nextCity]){
                pq.push({c + fees[nextCity], {t + nextTime, nextCity}});
                cost[nextCity] = c +fees[nextCity];
                time[nextCity] = t + nextTime;
            } else if(nextTime + t <= maxTime && t + nextTime < time[nextCity]){
                pq.push({c + fees[nextCity], {t + nextTime, nextCity}});
                cost[nextCity] = c +fees[nextCity];
                time[nextCity] = t + nextTime;
            }                                                                             
        }

    }

    return cost[n-1] == INT_MAX ? -1 : cost[n-1];

}


};