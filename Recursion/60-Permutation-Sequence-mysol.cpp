class Solution {
public:
    void rec(string num ,string& res, int index, int& k){
      
        if (index==num.size()){
            k=k-1;
          
            
        if(k==0){
            res= num;
            
        }
            return;
    }
        

        
        for(int i=index;i<num.size();i++){
           
            swap(num[index], num[i]);
           
            rec(num, res,  index+1, k);
        }
    }
    
    string getPermutation(int n, int k) {
        string num;
        
        for(int i=1;i<=n;i++){
            num+=to_string(i);
        }
        string res;
       
        rec(num, res, 0, k);
         
        return res;
    }
};
