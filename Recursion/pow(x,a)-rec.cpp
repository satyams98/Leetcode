double powX(double x, int a){
    if (a==0)
        return 1;
    if(a==1)
        return x;
    
    if(a>0){
        
        if(a&1){
            return powX(x, a/2)*powX(x, a/2)*x;
            }
        return powX(x, a/2)*powX(x, a/2);
        
    }
    
    else{
        
        if(a&1){
        return powX(x, a/2)*powX(x, a/2)*1/x;
        }
        
        return powX(x, a/2)*powX(x, a/2);
        
    }
}

int main(){
    
    double x=0.5, a=-2;//a is integer +ve or negative
    cout<<powX(x, a);
}
