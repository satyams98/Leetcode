class Solution{
    private:
    
    void rec(vector<vector<int>> &m, vector<string>& res, string path, int i, int j, int n){
        
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0)
            return;
            
        if(i==n-1 && j==n-1){
            
            res.push_back(path);
            return;
            
        }
        
        m[i][j]=0;
        
            rec(m, res, path+'D', i+1, j, n);
            rec(m, res, path+'U', i-1, j, n);
            rec(m, res, path+'L', i, j-1, n);
            rec(m, res, path+'R', i, j+1, n);
        
        m[i][j]=1;
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
      
        vector<string> res;
        rec(m, res, "", 0, 0, n);
        return res;
    }
};
