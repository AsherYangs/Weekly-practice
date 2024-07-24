class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //use dfs, and set to mark nums if already visit (like graph.)
        sort(candidates.begin(),candidates.end()); /* 排序因為只從小到大搜索 */
        vector<int> temp;
        findSum(candidates, temp, target);
        return ans;
    }
    void findSum(vector<int>& vec, vector<int>& temp, int tar){
        if(tar==0){
            //fit  the target sum, queue it to ans
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<vec.size(); i++){
            if(tar-vec[i]>=0){
                //don't let vec[i] in vector if is little than last
                //cause that will be repeat
                if(temp.size()==0 || vec[i]>=temp.back()){
                    temp.push_back(vec[i]);
                    findSum(vec, temp, tar-vec[i]);
                    temp.pop_back();
                }
            }else if(tar-vec[i]<0){
                //if tar-vec[i]<0, represent this combination not fit
                return;
            }
        }
    }
};
