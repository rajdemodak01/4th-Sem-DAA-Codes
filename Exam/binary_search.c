#include<stdio.h>

int binary_search(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element to search\n");
    scanf("%d",&key);
    int ans=binary_search(arr,key,n);
    if(ans==-1){
        printf("Element is not present in the array.\n");
    }else{
        printf("Element is present at %d",ans);
    }
    return 0;
}