// Manish Kumar, IIIT Allahabad

https://leetcode.com/problems/prefix-and-suffix-search/

// Trie

class WordFilter {
public:
    struct Trie{
        Trie* child[26];
        vector<int> idx;
        Trie(){
            idx.clear();
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    
    Trie *pre, *suf;
    
    WordFilter(vector<string>& words) {
        pre = new Trie();
        suf = new Trie();
        
        unordered_map<string, int> m;
        
        for(int i = 0; i < words.size(); i++)
            m[words[i]] = i;
        
        for(auto [s, i] : m){
            Trie* temp = pre;
            for(int j = 0; j < s.size(); j++){
                if(!temp->child[s[j]-'a']){
                    temp->child[s[j]-'a'] = new Trie();
                }
                temp = temp->child[s[j]-'a'];
                temp->idx.push_back(i);
            }
            temp = suf;
            for(int j = s.size()-1; j>=0; j--){
                if(!temp->child[s[j]-'a']){
                    temp->child[s[j]-'a'] = new Trie();
                }
                temp = temp->child[s[j]-'a'];
                temp->idx.push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        unordered_map<int, int> m;
        Trie* temp = pre;
        for(char c: prefix){
            if(!temp->child[c-'a'])
                return -1;
            temp = temp->child[c-'a'];
        }
        
        for(int i:temp->idx)
            m[i]++;
        
        temp = suf;
        for(int i = suffix.size()-1; i>=0; i--){
            if(!temp->child[suffix[i]-'a'])
                return -1;
            temp = temp->child[suffix[i]-'a'];
        }
        
        vector<int> v = temp->idx;
        
        sort(v.begin(), v.end(), greater<int>());
        for(auto i:v)
            if(m.find(i) != m.end())
                return i;
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
