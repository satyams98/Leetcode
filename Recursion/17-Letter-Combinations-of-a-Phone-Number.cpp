class Solution {
private:
    void rec(string digits, string output, vector<string>& ans, vector<string> mapping, int index){
        
        if(index==digits.size()){
            if(output.size()!=0)
                ans.push_back(output);
            return;
        }
        
        int element  = digits[index]-'0';
        string mapped = mapping[element];
        
        for(char c:mapped){
            
            rec(digits, output+c, ans, mapping, index+1);
            
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
       
        vector<string> mapping={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
                           
        rec(digits, "", ans, mapping, 0);
        
        return ans;
        
    }
};
