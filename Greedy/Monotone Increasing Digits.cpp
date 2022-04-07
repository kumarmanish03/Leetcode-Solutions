// Manish Kumar, IIIT Allahabad
// Easy, observation, greedy

https://leetcode.com/problems/monotone-increasing-digits/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int l = s.size();
        for(int i = l-2; i >= 0; i--){
            if(s[i] <= s[i+1]){
                continue;
            }
            else{
                s[i]--;
                int k = i+1;
                while(k < l){
                    s[k] = '9';
                    k++;
                }
            }
        }
        return stoi(s);
    }
};
