void rec(vector<int>& num, vector<int>& res, int ans, int index){
    if(index==num.size()){
        res.push_back(ans);
        return;
    }
    //not considering presente element
    rec(num, res, ans, index+1);
    //considering present element
    rec(num, res, ans+num[index], index+1);
    
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    rec(num, res, 0, 0);
    sort(res.begin(), res.end());
    return res;
    
}
