class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> l;
        vector<vector<int>> r;
        int start = newInterval[0];
        int end = newInterval[1];
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1]<start)
                l.push_back(intervals[i]);
            else if(intervals[i][0]>end)
                r.push_back(intervals[i]);
            else{
                start = min(start, intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<l.size(); i++)
            ans.push_back(l[i]);
        ans.push_back({start,end});
        for(int i=0; i<r.size(); i++)
            ans.push_back(r[i]);
        return ans;
    }
};
