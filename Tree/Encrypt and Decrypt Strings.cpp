// Manish Kumar, IIIT Allahabad
// Trie

https://leetcode.com/problems/encrypt-and-decrypt-strings/

class Encrypter {
public:
    struct Trie{
        Trie *child[26];
        Trie(){
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    
    Trie* d;
    
    unordered_map<string, vector<char>> v;
    unordered_map<string, int> dict;
    vector<string> data;
    unordered_map<string, int> decrypted;
    
    int cnt;
    
    void insert(string s, Trie* head){
        Trie* curr = head;
        for(char c:s){
            if(!curr->child[c-'a'])
                curr->child[c-'a'] = new Trie();
            curr = curr->child[c-'a'];
        }
    }
    
    bool search(string s, Trie* head){
        Trie* curr = head;
        for(char c:s){
            if(!curr->child[c-'a'])
                return false;
            curr = curr->child[c-'a'];
        }
        return true;
    }
    
    Encrypter(vector<char>& key, vector<string>& val, vector<string>& dictionary) {
        d = new Trie();
        v.clear();
        cnt = 0;
        dict.clear();
        data.resize(26, "");
        decrypted.clear();
        
        for(string s:dictionary){
            insert(s, d);
            dict[s]++;
        }
        
        for(int i = 0; i < key.size();i++){
            data[key[i]-'a'] = val[i];
                // cout<<val[24];
        } 
        
        for(int i = 0; i < val.size(); i++){
            v[val[i]].push_back(key[i]);
        }
        
               
        
    }
    
    void recur(string s, string t, int i){
        if(i >= s.size()){
            if(dict[t])
                cnt++;
            return;
        }
        
        if(search(t, d) == false)
            return;
        
        string q = s.substr(i, 2);
        for(char x:v[q])
            recur(s, t+x, i+2);
    }
    
    string encrypt(string word1) {
        string res="";
        for(int i = 0; i < word1.size(); i++){
            res += data[word1[i]-'a'];
        }
        return res;
    }
    
    int decrypt(string word2) {
        if(decrypted.find(word2) != decrypted.end())
            return decrypted[word2];
        cnt = 0;
        string t = "";
        int i = 0;
        recur(word2, t, i);
        return decrypted[word2] = cnt;
    }
};
