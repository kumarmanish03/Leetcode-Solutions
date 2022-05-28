/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
* @observation: The height of largest area histogram having height of one of the bar
* # calcultaing for each bar, area of histogram of that length, and maximize it
*
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && ht[i] < ht[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && ht[i] < ht[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout << left[i] << " " << right[i] << "\n";
            int curr = (right[i] - left[i] - 1) * ht[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};