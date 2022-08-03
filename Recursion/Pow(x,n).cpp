class Solution {
public:
    double rec(double x, int n){
         if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        
         double y = rec(x, n / 2);
        
        if(n%2==0)
            return y*y;
        
        return n>0?  y*y*x : y*y*1/x;
         
    }
    double myPow(double x, int n) {
        
       return rec(x, n);
        
    }
};
