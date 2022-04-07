// By Manish Kumar (IEC2019068), IIIT Allahabad
// Easy
// https://leetcode.com/problems/sentence-similarity-iii/ 

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> a, b;
        stringstream s1(sentence1);
        stringstream s2(sentence2);
        string s;
        while(s1 >> s)
            a.push_back(s);
        while(s2 >> s)
            b.push_back(s);
        
        while(a.size() > 0 && b.size() > 0 && a.front() == b.front()){
            a.pop_front();
            b.pop_front();
        }
        while(a.size() > 0 && b.size() > 0 && a.back() == b.back()){
            a.pop_back();
            b.pop_back();
        }
        
        if(a.size() == 0 || b.size() == 0)
            return true;
        return false;
    }
};