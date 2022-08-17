class Solution {
private:
    void rec(vector<int>& nums, vector<vector<int>>&res, vector<int> ans, int index ){
        if(index==nums.size()){
            sort(ans.begin(), ans.end());
            if(find(res.begin(), res.end(), ans)==res.end())
                res.push_back(ans);
            return;
        }
        
        rec(nums, res, ans, index+1);
        ans.push_back(nums[index]);
        rec(nums, res, ans, index+1);
        ans.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, res, {}, 0);
        sort(res.begin(), res.end());
        return res;
        
    }
};
