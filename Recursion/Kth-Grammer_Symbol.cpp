class Solution {
public:
    int rec(int i, int j){
        if(i==0||j==0)
            return 0;
        
        if(i==1 && j==1)
            return 1;
        
        
        if(j%2==0) 
            return rec(i-1, j/2);
        else
            return !rec(i-1, j/2);      
             
    }
    int kthGrammar(int n, int k) {
     
        return rec(n-1, k-1);
         
    }
};

//note that, here, memoization will not optimise anything, will just use load of space
