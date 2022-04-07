// Manish Kumar, IIIT Allahabad
// Medium

https://leetcode.com/problems/number-of-visible-people-in-a-queue/

// Strategy : Next Greater Element Modified

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        vector<int> res(n);
        int cnt;
        for(int i = n-1; i >= 0; i--){
            cnt = 0;
            // cnt count element which are smaller than current 
            while(!st.empty() && h[i] > st.top()){
                cnt++;
                st.pop();
            }
            // If stack is empty that no element is gretaer than current so add 0
            // And if stack is not empty so add 1 for element which is greater than current
            res[i] = cnt + (st.empty() ? 0 : 1);
            st.push(h[i]);
        }
        return res;
    }
};