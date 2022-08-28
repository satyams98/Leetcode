vector<int> maxSubArraySum(int *arr, int n){
    
    int global_max=INT_MIN;
    int local_max=0;
    int start, end, temp;
    vector<int> maxAtI(n, INT_MIN);
    start =0;
   for(int i=0;i<n;i++){
      
       if(arr[i]> arr[i]+local_max){
           local_max=arr[i];
           start=i;
           
       } else {
           local_max = arr[i]+local_max;
       }
       
       if(local_max>global_max){
           end = i;
           global_max= local_max;
          
       }
   }
    
    return {start, end};
}
int main() {
    int arr[]={1,2,3,-2,5};
    vector<int> res = maxSubArraySum(arr, 5);
    for(int c: res)
        cout<<c<<" ";
    
}
