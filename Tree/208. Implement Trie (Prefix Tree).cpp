
/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/implement-trie-prefix-tree/
* @desc: exact solution you can see in leetcode submissions
*
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node *next[26];
    bool isEnd;

    node(){
        for(auto &c:next){
            c = NULL;
        }
        isEnd = false;
    }
};

node *root;

// insert word in trie
void insert(string word) {
    node *temp = root;
    for(char c:word){ 
        if(!temp->next[c-'a']){
            temp->next[c-'a'] = new node();
        }
        temp = temp->next[c-'a'];
    }
    temp->isEnd = true;
}

// search for complete word
bool search(string word) {
    node *temp = root;
    for(char c: word){
        if(!temp->next[c-'a']){
            return false;
        }
        temp = temp->next[c-'a'];
    }
    
    return temp->isEnd;
}

// search for prefix
bool startsWith(string word) {
    node *temp = root;
    for(char c: word){
        if(!temp->next[c-'a']){
            return false;
        }
        temp = temp->next[c-'a'];
    }
    
    return true;
}


int main(){

    root = new node();

    insert("manish");
    insert("nisha");
    cout << search("man") << "\n";
    cout << startsWith("man") << "\n";
    cout << startsWith("mai") << "\n";
    cout << search("manish") << "\n";
    cout << search("nisha") << "\n";

    return 0;
}