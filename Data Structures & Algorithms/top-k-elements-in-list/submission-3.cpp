class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int,int>M;

        for(auto n:nums){
            M[n]++;
        }

        vector<pair<int,int>>V;
        for(auto ele:M){
            V.push_back({ele.second,ele.first});
        }
        sort(V.begin(),V.end(),greater<>());

        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(V[i].second);
        }
        return res;
    }
};
