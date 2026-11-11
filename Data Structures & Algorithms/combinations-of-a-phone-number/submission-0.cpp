class Solution {
public:
   vector<string>res;
   vector<string>digitToChar={"","","abc","def","ghi","jkl",    
   "mno", "pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return res;
        string curr;
        backtrack(digits ,curr,0);
        return res;
    }

    void backtrack(string digits,string curr,int idx){
        if(idx >= digits.length()){
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[idx]-'0'];

        for(int i=0;i<chars.length();i++){
            curr.push_back(chars[i]);
            backtrack(digits,curr,idx+1);
            curr.pop_back();
        }
    }
};
