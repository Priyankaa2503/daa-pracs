#include<stdio.h>

void merge(int arr[],int p, int q, int r){
    int i = p;
    int j = q+1;
    int k = p;
    int b[100];
    
    while(i<=q && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    if(i>q)
    {
        while(j<=r)
        {
            b[k]=arr[j];
            k++;
            j++;

        }
    }
    else{
        while(i<=q)
        {
            b[k]=arr[i];
            k++;
            i++;
        }
    }
    for (int k = p; k <= r; k++)
    {
        arr[k]=b[k];
       
    }    
}
void mergeSort(int arr[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}
int main(){
    int arr[] = {23,47,28,79,91,45,32,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting:\n");
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printf("Array after sorting:\n");
    printArray(arr,n);
    return 0;
}