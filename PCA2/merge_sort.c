#include<stdio.h>

void mergeSort(int arr[],int s,int e,int n){
    if(s<e){
        // printf("ok");
        int mid=(s+e)/2;
        mergeSort(arr,s,mid,n);
        mergeSort(arr,mid+1,e,n);

        int i=s;
        int j=mid+1;
        int k=0;
        int ans[e-s+1];
        while(i<=mid && j<=e){
            if (arr[i] <= arr[j]) { // Changed the condition to compare array elements
                ans[k++] = arr[i++];
            } else {
                ans[k++] = arr[j++];
            }
        }
        while(i<=mid){
                ans[k++]=arr[i++];
        }
        while(j<=e){
                ans[k++]=arr[j++];
        }
        for(int i=0;i<k;i++){
            arr[s+i]=ans[i];
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element of the array: \n");
        scanf("%d",&arr[i]);
    }
    printArray(arr,n);
    mergeSort(arr,0,n-1,n);
    printArray(arr,n);
    return 0;
}