// Maniss Kumar, IIIT Allahabad
// Medium

https://leetcode.com/contest/biweekly-contest-56/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int, pair<int, int>>> qu; // {distance, {i, j}}
        int n = maze.size();
        int m = maze[0].size();
        int dx[] = {0, 0, -1, +1};
        int dy[] = {-1, +1, 0, 0};
        qu.push({0, {e[0], e[1]}});
        maze[e[0]][e[1]] = '+';
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                pair<int, pair<int, int>> t = qu.front();
                qu.pop();
                
                int i = t.second.first;
                int j = t.second.second;
                for(int k = 0; k < 4; k++){
                    int p = i + dx[k];
                    int q = j + dy[k];
                    if(!isValid(p, q, n, m) || maze[p][q] == '+')
                        continue;
                    if(p == 0 || q == 0 || p == n-1 || q == m-1)
                        return t.first+1;
                    maze[p][q] = '+';
                    qu.push({t.first+1, {p, q}});
                }
            }
        }
        return -1;
    }
};