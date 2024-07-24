class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left+1]==nums[left])
                        left++;
                    left++;
                    while(left<right && nums[right-1]==nums[right])
                        right--;
                    right--;
                }else if(sum>0)
                    right--;
                else if(sum<0)
                    left++;
            }
        }
        return ans;
    }
};
