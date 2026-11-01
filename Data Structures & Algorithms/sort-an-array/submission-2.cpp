class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       merge_sort(nums,0,nums.size()-1);
       return nums;
    }

private:
    void merge_sort(vector<int>&nums,int l,int h){
        if(l>=h)return;
        int mid=(l+h)/2;

        merge_sort(nums,l,mid);
        merge_sort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }

    void merge(vector<int>&nums,int l,int mid,int h){
        vector<int>res;
        int i=l;
        int j=mid+1;

        while(i<=mid &&j<=h){
            if(nums[i]<=nums[j]){
                res.push_back(nums[i++]);
            }else{
                res.push_back(nums[j++]);
            }
        }

        while(i<=mid){
            res.push_back(nums[i++]);
        }
        while(j<=h){
            res.push_back(nums[j++]);
        }
        
        int k=0;
        for(int i=l;i<=h;i++){
            nums[i]=res[k];
            k++;
        }
        
    }
};