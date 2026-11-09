class Solution {
public:
    vector<bool>used;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum % k !=0)return false;
        int length=sum/k;
        sort(nums.rbegin(),nums.rend());
        used.assign(nums.size(),false);
        return backtrack(nums,k,0,0,length);
        
    }

    bool backtrack(vector<int>&nums,int k,int curr,int idx,int length){
        if(k==0)return true;
        if(curr==length)return backtrack(nums,k-1,0,0,length);

        for(int i=idx;i<nums.size();i++){
            if(used[i] || curr+nums[i]>length)continue;
            used[i]=true;
            if(backtrack(nums,k,curr+nums[i],i+1,length))return true;
            used[i]=false;

            if(curr==0)return false;

        }
        return false;
    }
};