class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx, int left, vector<int> p, vector<int> candidates)
    {
        if(left == 0)
        {
            ans.push_back(p);
            return;
        }
        else if(left < 0 or idx > candidates.size()-1)
            return;
        vector<int> temp = p;
        temp.push_back(candidates[idx]);
        helper(idx , left - candidates[idx], temp, candidates);
        helper(idx + 1, left, p, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(0, target, {}, candidates);
        return ans;
    }
};
