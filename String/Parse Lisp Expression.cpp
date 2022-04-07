// Manish Kumar, IIIT Allahabad
// Hard

https://leetcode.com/problems/parse-lisp-expression/

class Solution {
public:
    // for parsing expressions
    string parse(int &i, string &s){
        int k = i+1, cnt = 1, start = i;
        if(s[i] == '('){
            while(cnt != 0){
                if(s[k] == '(')
                    cnt++;
                else if(s[k] == ')')
                    cnt--;
                k++;
            }
        }
        else{
            while(k < s.size() && s[k] != ' '){
                k++;
            }
        }
        i = k+1;
        return s.substr(start, k-start);
    }
    
    int help(string exp, unordered_map<string, int> m){
        if(exp[0] == '-' || (exp[0] >= '0' && exp[0] <= '9')){
            return stoi(exp);
        }
        else if(exp[0] != '('){
            return m[exp];
        }
        // for deleting ends '(' & ')'
        exp = exp.substr(1, exp.size()-2);
        int i = 0;
        string s = parse(i, exp);
        if(s == "let"){
            while(1){
                string var = parse(i, exp);
                
                if(i > exp.size())
                    return help(var, m);
                
                m[var] = help(parse(i, exp), m);
            }
        }else if(s == "add"){
            return help(parse(i, exp), m) + help(parse(i, exp), m);
        }else{
            return help(parse(i, exp), m) * help(parse(i, exp), m);
        }
    }
    
    int evaluate(string exp) {
        unordered_map<string, int> m;
        return help(exp, m);
        // int i = 0;
        // while(i < exp.size()){
        //     cout << parse(i, exp) << "\n";
        // }
        
        return 0;
    }
};