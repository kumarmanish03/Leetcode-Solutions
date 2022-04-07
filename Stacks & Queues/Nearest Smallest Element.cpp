// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(n)

// ====================================

https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> v(temp.size());
        stack<int> st;
        for(int i = 0; i < temp.size(); i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};

// ====================================

https://www.interviewbit.com/problems/nearest-smaller-element/
https://www.youtube.com/watch?v=T-E3hWEPWWU&t=465s

// There are four variations of this question, next greater element(from left and right) and next smaller element(from left and right) 
// Since this ques asked for nearest smaller to left, hence we started from back of array(see loop)
// In above yt video next greater element asked from right
// Try to done this question self and understand all those cases


// Approach 2

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();

    vector<int> v(n, -1);
    for(int i = 0; i < A.size(); i++){
        // Deleting all previous elements which are greater than current
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();
        
        if(!s.empty())
            v[i] = A[s.top()];
        
        s.push(i);
    }

    return v;
}


// ========================================
// Approach 3

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    for(int i = A.size() - 1; i >= 0; i--){
            while(!s.empty() && A[i] < A[s.top()]){
                    A[s.top()] = A[i];
                    s.pop();
            }
            s.push(i);
    }

    while(!s.empty()){
        A[s.top()] = -1;
        s.pop();
    }
    
    return A;
}
