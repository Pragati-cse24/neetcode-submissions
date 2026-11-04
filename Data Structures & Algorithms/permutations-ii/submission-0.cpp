class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        backtrack(nums,0,res);
        return res;
    }

    void backtrack(vector<int>&nums,int idx,vector<vector<int>>&res){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        
        unordered_set<int>used;

        for(int i=idx;i<nums.size();i++){
            if(used.count(nums[i]))continue;
            used.insert(nums[i]);
            swap(nums[idx],nums[i]);
            backtrack(nums,idx+1,res);
            swap(nums[idx],nums[i]);
        }
    }
};