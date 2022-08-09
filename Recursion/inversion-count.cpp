void merge(vector<int> &arr, int i, int mid, int j, int& count){
   
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
   
    for(int index1=0;index1<len1;index1++){
        for(int index2=0;index2<len2;index2++){
            if(arr1[index1]>arr2[index2])
                count++;
        }
    }  
   
    delete [] arr1;
    delete [] arr2;
    
}

void mergeSort(vector<int> &arr, int i, int j, int& count){
      
    if(i>=j)
        return;
    
    int mid= (i+j)/2;
    
    mergeSort(arr, i, mid, count);
    mergeSort(arr, mid+1, j, count);
  
    merge(arr, i, mid, j, count);
    
}

int main() {
        vector<int> arr={8,4,2,1, -1};
        int count=0;
        mergeSort(arr, 0, arr.size()-1, count);
        cout<<count;
             
}
