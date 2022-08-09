int partition(int *arr, int s, int e){
    
    int i=s-1;
    
    //j will filter all the elements below the arr[e] in the range 0-i
    
    for(int j=s;j<e;j++){
        if(arr[j]<arr[e]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    
    return i+1;  
}

void quickSort(int *arr, int s, int e){
    if(s>=e)
        return;
    
    int p = partition(arr, s, e);
    //after partion, p will be at its point
    
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
    
}

int main(){
    int arr[6]={1, 5,25,2,13,11};
    quickSort(arr, 0, 5);
    for (int x: arr){
        cout<<x<<" ";
    }
}
