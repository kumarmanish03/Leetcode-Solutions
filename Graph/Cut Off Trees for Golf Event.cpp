// Manish Kumar, IIIT Allahabad
// Medium-Hard
// TC: O(mn^2)
// SC: O(mn)

// Since we have to cut trees min to max height
// Then, first we sort trees(acc. to height) and calculate min step to reach b/w each adjacent trees

https://leetcode.com/problems/cut-off-trees-for-golf-event/


class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // return min steps b/w tree at posn (sx, sy) to (i, j)
    int bfs(int sx, int sy, int i, int j, vector<vector<int>>& fst){
        int m = fst.size();
        int n = fst[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{sx, sy}, 0});
        vis[sx][sy] = true;
        
        auto isValid = [&](int x, int y){
            if(x >= 0 and x < m && y >= 0 and y < n and fst[x][y] and !vis[x][y])
                return true;
            return false;
        };
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [pos, step] = q.front();
                auto [x, y] = pos;
                q.pop();
                
                if(x == i and y == j){
                    return step;
                }
                for(int k = 0; k < 4; k++){
                    if(isValid(x + dx[k], y + dy[k])){
                        q.push({{x+dx[k], y+dy[k]}, step+1});
                        vis[x+dx[k]][y+dy[k]] = true;
                    }
                }
            }
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& fst) {
        int m = fst.size();
        int n = fst[0].size();
        vector<pair<int, int>> v;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(fst[i][j] > 1){
                    v.push_back({i, j});
                }
            }
        }
        
        // sorting tress posn acc to their heights
        sort(v.begin(), v.end(), [&](auto&x, auto&y){
           return fst[x.first][x.second] < fst[y.first][y.second];
        });
        
        int sx = 0;
        int sy = 0;
        int total_steps = 0;
        for(auto cell:v){
            auto [i, j] = cell;
            
            int step = bfs(sx, sy, i, j, fst);
            
            if(step == -1)
                return -1;
            
            // calculate total steps
            sx = i;
            sy = j;
            total_steps += step;
        }
        return total_steps;
    }
};
