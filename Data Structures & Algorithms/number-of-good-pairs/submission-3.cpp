class Solution{
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int>M;

        for(auto n:nums){
            M[n]++;
        }
        
        int count=0;
        for(auto n:M){
           count+=n.second*(n.second-1)/2;
        }
        return count;
    }
};