// Manish Kumar, IIIT Allahabad
// Medium

// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(auto a : ast){
            int destroyed = false;
            while(s.size() && s.top() > 0 && a < 0 && !destroyed){
                if(abs(s.top()) > abs(a)) 
                    destroyed = true;
                else if(abs(s.top()) < abs(a))
                    s.pop();
                else{
                    destroyed = true;
                    s.pop();
                }
            }
            if(!destroyed) s.push(a);
        }
        
        ast.clear();
        
        while(!s.empty()){
            ast.push_back(s.top());
            s.pop();
        }
        
        reverse(ast.begin(), ast.end());
        
        return ast;
    }
};