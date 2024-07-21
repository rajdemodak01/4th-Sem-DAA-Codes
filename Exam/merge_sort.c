#include<stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void merge_sort(int arr[],int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        printf("s=%d, e=%d,mid=%d\n",s,e,mid);
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        printf("s=%d, e=%d,mid=%d\n",mid);
        int i=s;
        int j=mid+1;
        int k=0;
        int ans[e-s+1];
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                ans[k++]=arr[i++];
            }else{
                ans[k++]=arr[j++];
            }
        }
        while(i<=mid){
                ans[k++]=arr[i++];
        }
        while(j<=e){
                ans[k++]=arr[j++];
        }
        printArray(ans,e-s+1);
        for(i=0;i<e-s+1;i++){
            arr[s+i]=ans[i];
        }
    }
}


int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    printArray(arr,n);
    merge_sort(arr,0,n-1);
    printArray(arr,n);
}