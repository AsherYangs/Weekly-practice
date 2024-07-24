class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        int cur = nums[0];
        //從頭開始先第一個數預設, 其他相乘
        for(int i=1; i<nums.size(); i++){
            ans[i] = cur;
            cur *= nums[i];
        }
        //顛倒也做一次, 維持最後一個數
        cur = nums[nums.size()-1];
        //其他依序相乘
        for(int i = nums.size()-2; i>=0; i--){
            ans[i] *= cur;
            cur *= nums[i];
        }
        return ans;
    }
};
