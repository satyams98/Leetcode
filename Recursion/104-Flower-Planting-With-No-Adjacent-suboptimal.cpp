class Solution {
    
private:
    bool isSafe(vector<int>& planted, vector<vector<int>>& adjacency, int flower, int garden){
        
        for(auto gardens: adjacency[garden]){
            if(planted[gardens-1]==flower)
                return false;
        }
        return true;
    }
        
    bool utility(vector<int>& planted, vector<vector<int>>& adjacency, int n, int garden){
        
        if(garden>n)
            return false;
        
        if(!adjacency[garden].size()){
            
            planted[garden-1]=1;
            
             if(utility(planted, adjacency, n, garden+1))
                    return true;
            
            return false;
            
        }
        
        for(int i=1; i<=4; i++){
            
            if(isSafe(planted, adjacency, i, garden)){
                planted[garden-1]=i;
                
                if(utility(planted, adjacency, n, garden+1))
                    return true;
                
                planted[garden-1] =-1;
            }
        }
        
        return false;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       
        
        vector<int> planted(n, -1);
        int garden = 1;
        vector<vector<int>> adjacency(n+1);
        
        
        for(auto path: paths){
            adjacency[path[0]].push_back(path[1]);
            adjacency[path[1]].push_back(path[0]);
        }
        
        utility(planted, adjacency, n, garden);
        
        return planted;
    }
};
