class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& res){
        if(i==j||i==0||j==0){
            res[i][j]=1;
            return 1;
        
        }   
        
        if(res[i][j]!=0){
            return res[i][j];
        }
        
        res[i][j]=rec(i-1, j-1, res)+rec(i-1, j, res);
        return res[i][j];
        
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>res(rowIndex+1, vector<int>(rowIndex+1, 0));
        
       for(int i=0;i<=rowIndex;i++)
          rec(rowIndex, i, res);
        
        return res[rowIndex];
    }
};
