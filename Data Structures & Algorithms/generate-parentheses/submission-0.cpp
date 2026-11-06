class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr;
        backtrack(0,0,n,res,curr);
        return res;
    }

    void backtrack(int closed,int open,int n,vector<string>&res,string &curr){
       if(open==closed && open==n){
        res.push_back(curr);
        return;
       }

       if(open<n){
        curr+='(';
        backtrack(closed,open+1,n,res,curr);
        curr.pop_back();
       }

       if(closed < open){
        curr+=')';
        backtrack(closed+1,open,n,res,curr);
        curr.pop_back();
       }

    }
};
