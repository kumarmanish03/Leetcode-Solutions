// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(nlog(m))
// Space Complexity : O(1)

https://www.interviewbit.com/problems/allocate-books/

https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Solve above Leetcode problem first as it is more easily to understand
// Make search space carefully, Do not take lo = 0 (this is not correct), instead lo = maximum of all elements and hi = sum of all elements
// Strategy :
// We will run binary search on no. of pages where lo = max element(becoz it is the least possible from maximum)
// and hi = sum of all elements(possible when 1 student read all pages)
// Then using binary search, we try to minimize pages such that, it is possible for reading B students 

// This function tells about the no. of students who can read atmost 'capacity' pages
bool isPossible(vector<int> v, int capacity, int B){
    int sum = 0;
    int count = 1;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        if(sum > capacity){
            count++;
            sum = v[i];
        }
    }
    
    return count <= B;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    
    int lo = INT_MIN;
    int hi = 0;
    for(auto i:A){
        hi += i;
        lo = max(i, lo);
    }
    
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(isPossible(A, mid, B)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    
    if(isPossible(A, lo, B)){
        return lo;
    }
    else if(isPossible(A, hi, B))
        return hi;
    
}
