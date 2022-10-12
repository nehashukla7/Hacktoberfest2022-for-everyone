class Solution {
public:
    void acropermute(int idx,vector<vector<int>>&ans,vector<int>&nums){
        if(idx==nums.size()){
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            acropermute(idx+1,ans,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        acropermute(0,ans,nums);
        return ans;
    }
};
