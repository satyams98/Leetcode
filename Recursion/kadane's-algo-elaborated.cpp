int local_max_at(vector<int>& maxAtI,int *arr,  int index, int n){
    
    if(index==n-1){
        maxAtI[index]= arr[index];
    }
    
    if(maxAtI[index]!=INT_MIN)
        return maxAtI[index];
    
    maxAtI[index] = max(arr[index], arr[index] + local_max_at(maxAtI, arr, index+1, n) );
    return maxAtI[index];
}

int maxSubArraySum(int *arr, int n){
    
    int global_max=INT_MIN;
    int local_max;
    int start, end, temp;
    vector<int> maxAtI(n, INT_MIN);
    
    for(int i=n-1; i>=0; i--){
        local_max = local_max_at(maxAtI, arr, i, n);
        
        global_max = max(local_max, global_max);
    }
    
    return global_max;
}
int main() {
    int arr[]={-1,-2,-3,-4};
    cout<< maxSubArraySum(arr, 4);
    
}
