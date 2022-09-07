class Solution {
public:
    bool isSafe(vector<string>& path, int row, int col, int n){
     
        
        //check previous cols
        for(int i=0; i<col; i++)
            if(path[row][i]=='Q')
                return false;
        
        // Check upper diagonal on left side 
        int i, j;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (path[i][j]=='Q')
            return false;
  
    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (path[i][j]=='Q')
            return false;
        
        return true;
    }
    
    void utility(vector<vector<string>>& res, vector<string>& ans, int col, int n){
        
        if(col==n){
            res.push_back(ans);   
            return;
        }
        
        for(int row=0;row<n;row++){
            
            if(isSafe(ans, row, col, n)){
                ans[row][col] = 'Q';
                
            utility(res, ans, col+1, n);
                
                
              ans[row][col]='.';
                
            }
        }
       
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>  res;
        string row = "";
        
        for (int i =0;i<n;i++)
            row+=".";
        
        vector<string> path(n, row);
      
        utility(res, path, 0, n);      
        
        return res;
          
    }
};
