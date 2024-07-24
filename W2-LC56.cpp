class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
            return intervals;
        //sort first to easy to merge
        sort(intervals.begin(),intervals.end());

        //use first interval to start
        int begin = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++){
            vector<int> temp;
            //if overlap next interval, then merge it
            if(end>=intervals[i][0]){
                end = max(end,intervals[i][1]);
                if(i==intervals.size()-1)
                    ans.push_back({begin,end});
            }else{ //if not overlap put this interval to ans
                temp.push_back(begin);
                temp.push_back(end);
                ans.push_back(temp);
                begin = intervals[i][0];
                end = intervals[i][1];
                if(i==intervals.size()-1)
                    ans.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
            }
        }
        return ans;
    }
};
