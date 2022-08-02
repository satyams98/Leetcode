//pascal's triangle
int pascalsTriangle(int i, int j){
    
    if(i==0||j==0||i==j)
        return 1;
    
    return pascalsTriangle(i-1, j-1)+pascalsTriangle(i-1, j);
  
}
int main() {
    //find the value of f(4,2), 0th index row and cols
    cout<<pascalsTriangle(4,2);
}
