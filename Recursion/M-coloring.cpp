bool isSafe(vector<int>& path, vector<vector<int>>& edges, int color, int edge){
        
        //check is egde adjacent edges have same color
        for(auto adges: edges[edge]){
            if(path[adges]==color)
                return false;
        }
        
        return true;
    }
    
    bool utility(vector<int>& path, vector<vector<int>>& edges, int m, int n, int edge){
        
        if(edge==n)
            return true;
            
            
        //try every color
        
        for(int i=0; i<m;i++){
            
            //check for constriant
            
            if(isSafe(path, edges, i, edge)){
                path[edge]=i;
                
                if(utility(path, edges, m ,n, edge+1))
                        return true;
                        
                path[edge]=-1;
            }
        }
        
        return false;
            
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        //create a adjacency matrix
        vector<vector<int>> adjacency(101);
        
        for(int i=0; i<101;i++){
           for(int j=0; j<101; j++){
               
               if(graph[i][j])
                    adjacency[i].push_back(j);
           }
        }
        
        vector<int> path(n, -1);
        int vertex;        
        for(int i=0; i<101;i++){
            if(adjacency[i].size()){
                vertex =i;
                break;
            }
        }
       return  utility(path, adjacency, m, n, vertex);
        
        
    }
