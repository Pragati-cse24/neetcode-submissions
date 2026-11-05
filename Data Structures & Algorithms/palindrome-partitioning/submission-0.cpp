class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        vector<string>ch;
        vector<vector<string>>res;
        backtrack(s,0,ch,res);
        return res;
    }

    void backtrack(string &s,int i,vector<string> &ch,vector<vector<string>>&res){
        if(i>=s.length()){
            res.push_back(ch);
            return;
        }

        for(int j=i;j<s.length();j++){
            if(isPalin(s,i,j)){
                ch.push_back(s.substr(i,j-i+1));
                backtrack(s,j+1,ch,res);
                ch.pop_back();
            }
        }


    }

    bool isPalin(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
