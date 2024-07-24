class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,int>::iterator it;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i]) != m.end()){
                ans.push_back(i);
                ans.push_back(m.find(target-nums[i])->second);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
