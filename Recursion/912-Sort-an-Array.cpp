class Solution {
public:
    //merge sort rcursion
void merge(vector<int> &arr, int i, int mid, int j){
   
    if(i>=j)
        return;
    int len1 = mid-i+1;
    int len2= j-mid;
    int *arr1 = new int[len1];
    int *arr2  = new int[len2];
    int mainArrayIndex = i;
    
    for(int k=0;k<len1;k++)
        arr1[k]= arr[mainArrayIndex++];
    
    for(int k=0;k<len2;k++)
        arr2[k] = arr[mainArrayIndex++];
    
    mainArrayIndex = i;
    int index1=0, index2=0;
    
    while(index1<len1 && index2<len2){
        if(arr1[index1]<=arr2[index2]){
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else{
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }
    
    while(index1<len1){
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while(index2<len2){
         arr[mainArrayIndex++] = arr2[index2++];
    }
    delete [] arr1;
    delete [] arr2;
    
}
void mergeSort(vector<int> &arr, int i, int j){
      
    if(i>=j)
        return;
    
    int mid= (i+j)/2;
    
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
  
    merge(arr, i, mid, j);
    
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
        
    }
};
