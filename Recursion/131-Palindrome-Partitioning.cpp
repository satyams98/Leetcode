class Solution {
private:
    bool isPalindrome(string s) {
        int start =0, end= s.size()-1;
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
    
    void rec(string s, vector<vector<string>>& res, vector<string> ans, int index){
        
        if(index==s.size()){
            res.push_back(ans);
            return;
        }
        
        for(int x=index; x< s.size(); x++){
            string op = s.substr(index, x-index+1); //substr(pos, len);
            
            if(isPalindrome(op)){
                
                ans.push_back(op);
                 rec(s, res, ans, x+1);
                ans.pop_back();
            }
                   
        }
                    
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        rec(s, res, {}, 0);
        return res;
    }
};
