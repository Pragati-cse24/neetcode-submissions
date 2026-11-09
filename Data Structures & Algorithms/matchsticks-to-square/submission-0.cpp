class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int TotalLength=accumulate(matchsticks.begin(),matchsticks.end(),0);

        if(TotalLength % 4 != 0)return false;
        int length=TotalLength/4;
        vector<int>sides(4,0);
        sort(matchsticks.rbegin(),matchsticks.rend());

        return backtrack(matchsticks,sides,0,length);
    }

    bool backtrack(vector<int>&matchsticks,vector<int>&sides,int idx,int length){
        if(idx==matchsticks.size()){
            return true;
        }

        for(int j=0;j<4;j++){
            if(sides[j] + matchsticks[idx]<=length){
                sides[j]+=matchsticks[idx];
                if(backtrack(matchsticks,sides,idx+1,length))return true;
                sides[j]-=matchsticks[idx];
            }
            if(sides[j]==0)break;
        }
        return false;
    }
};