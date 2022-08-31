class Solution {
public:
int fact(int x){
    if (x<=1)
        return 1;
    
    return x*fact(x-1);
}
    
void rec(string nums ,string& res, int index, int k){
      
      if(!nums.size())
          return;
    
    int perm = fact(nums.size()-1);
    int indexBlock = k/perm;
    k=k%perm;
    
    res+=nums[indexBlock];
    nums.erase(nums.begin()+indexBlock);
    rec(nums, res, index+1, k);
    
    }
    
    string getPermutation(int n, int k) {
        string num;
        
        for(int i=1;i<=n;i++){
            num+=to_string(i);
        }
        
        string res;
       
        rec(num, res, 0, k-1);
         
        return res;
    }
};
