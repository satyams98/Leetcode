class Solution {
    private:
        bool isSafe(vector<vector<int>>& adjacency,vector<int>& colored, int garden, int color){
            for(auto adja:adjacency[garden]){
                if(colored[adja-1]==color)
                    return false;
            }
            
            return true;
        }
    
    
        bool utility(vector<vector<int>>& adjacency,vector<int>& colored, int n, int garden){
            
            if(garden>n)
                return true;
            
            if(!adjacency[garden].size()){
                colored[garden-1]=1;
                
                return utility(adjacency, colored, n, garden+1);
                    
            }
            
            for(int i=1;i<=4;i++){
                if(isSafe(adjacency, colored, garden, i)){
                    colored[garden-1]=i;
                    
                    if(utility(adjacency, colored, n, garden+1))
                        return true;
                    
                    colored[garden-1]=0;
                    
                }
            }
            return false;
            
        }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adjacency(n+1);
        
        for(auto path: paths){
            adjacency[path[0]].push_back(path[1]);
             adjacency[path[1]].push_back(path[0]);
        }
        
        vector<int> colored(n, 0);
        
        utility(adjacency, colored, n, 1);
        
        return colored;
    }
};
