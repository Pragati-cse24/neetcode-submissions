class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         
       unordered_map<int,int>M;

       for(int i=0;i<nums1.size();i++){
         M[nums1[i]]=i;
       }
       
       vector<int>res(nums1.size(),-1);
       for(int i=0;i<nums2.size();i++){
         if(M.find(nums2[i])==M.end()){
            continue;
         }
         for(int j=i+1;j<nums2.size();j++){
            if(nums2[i]<nums2[j]){
               int index=M[nums2[i]];
               res[index]=nums2[j];
               break;
            }
         }
       }
       return res;
    }
};
 