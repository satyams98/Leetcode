class Solution {
private:
    void rec(vector<int> nums, vector<vector<int>>& ans, int index ){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(nums[i], nums[index]);
            rec(nums, ans, index+1);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(nums, ans, 0);
        return ans;
        
    }
};
