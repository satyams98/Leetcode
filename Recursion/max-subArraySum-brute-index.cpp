vector<int> maxSubArraySum(int *arr, int n){
    
    int global_max=INT_MIN;
    int local_max;
    int start, end, temp;
    
    
    for(int i=0;i<n;i++){
        local_max=0;
        temp=i;
        
        for (int j=i;j<n;j++){
            local_max+=arr[j];
             
            if(local_max>global_max){
                global_max = local_max;
                end = j;
                start = temp;
            }
        }
    }
    
    return {start, end};
}
int main() {
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> res = maxSubArraySum(arr, 8);
    for(int c: res)
        cout<<c<<" ";
    
}
