/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
* @desc: Tree + dp + Bitmask, Floyd Warshall algo
* @logic: Trick here to find valid subtree:
    # For a valid subtree of n vertces no. of edges should be n-1
*
*/


class Solution {
public:
    #define INF 1e4
    
    // For a valid subtree of n vertces no. of edges should be n-1
    int maxDist(int mask, vector<vector<int>> &tree, int n){
        
        int edge = 0;
        int mx = 0;
        int nodes = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                nodes++;
                for(int j = i+1; j < n; j++){
                    if(mask & (1 << j)){
                        if(tree[i+1][j+1] == 1){
                            edge++;
                        }
                        mx = max(mx, tree[i+1][j+1]);
                    }
                }
            }
        }
        
        if(edge == nodes-1 && mx > 0){
            return mx;
        }
        else{
            return -1;
        }
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n-1, 0);
        vector<vector<int>> tree(n+1, vector<int>(n+1, INF));
        for(int i = 0; i <= n; i++){
            tree[i][i] = 0;
        }
        for(auto e:edges){
            tree[e[0]][e[1]] = 1;
            tree[e[1]][e[0]] = 1;
        }
        
        // Floyd Warshell Algo
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    tree[i][j] = min(tree[i][j], tree[i][k] + tree[k][j]);
                }
            }
        }
        
        for(int mask = 0; mask < (1 << n); mask++){
            int d = maxDist(mask, tree, n);
            if(d > 0){
                res[d-1]++;
            }
        }
        
        return res;
    }
};