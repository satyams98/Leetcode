void merge(long long *arr, long long int start,  long long int end, long long int& count){
   
    if(start>=end)
        return;
    
    long long int mid= (start+end)/2;
    
    
    long long int *temp = new long long int[end-start+1];
    int beforeMid = start, afterMid = mid+1;
    int tempIndex=0;
    
    while(beforeMid<=mid && afterMid<=end){
        
        if(arr[beforeMid]<=arr[afterMid]) 
            temp[tempIndex++] = arr[beforeMid++];
            
        else{
            temp[tempIndex++] = arr[afterMid++];
            count+= mid-beforeMid+1;
        }
    }
    
    while(beforeMid<=mid)
        temp[tempIndex++] = arr[beforeMid++];
    
    while(afterMid<=end)
        temp[tempIndex++] = arr[afterMid++];
    
    tempIndex=0;
    for(int i= start;i<=end;i++)
        arr[i] = temp[tempIndex++];
   
    delete [] temp;

    
}

void mergeSort(long long *arr, long long int start, long long int end, long long int& count){
      
    if(start>=end)
        return;
    
    int mid= (start+end)/2;
    
    mergeSort(arr, start, mid, count);
    mergeSort(arr, mid+1, end, count);
  
    merge(arr, start, end, count);
    
}
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count=0;
        mergeSort(arr, 0, N-1, count);
        return count;
    }

};
