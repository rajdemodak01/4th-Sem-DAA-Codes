//merge_sort
#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[], int s, int e){
	if (s < e) {
        int m = (s + e) / 2;
		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, e);	
		
		int size1 = m - s + 1;
		int size2 = e - m;
		
		int arr1[size1];
		int arr2[size2];
		
		for(int i = 0; i < size1; i++){
			arr1[i] = arr[s + i];
		}
		
		for(int i = 0; i < size2; i++){
			arr2[i] = arr[m + 1 + i];
		}
		
		int i = 0, j = 0, k = s;
		while(i < size1 && j < size2){
			if(arr1[i] < arr2[j]){
				arr[k++] = arr1[i++];
			}else{
				arr[k++] = arr2[j++];
			}
		}
		
		while(i < size1){
			arr[k++] = arr1[i++];
		}
		
		while(j < size2){
			arr[k++] = arr2[j++];
		}
	}
}

void printArray(int *arr, int size){	
	for(int i = 0; i< size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i< size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("The unsorted array is: \n");
	
	printArray(arr, size);
	
	printf("The sorted array is: \n");
	mergeSort(arr, 0, size - 1);
	
	printArray(arr, size);
		
	return 0;
}






//binary_search
#include<stdio.h>

int binary_search(int arr[],int size,int val){
	int s=0,e=size-1;
	while(s<e){
		int mid=(s+e)/2;
		if(arr[mid]==val){
			return mid;
		}else if(arr[mid]>val){
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	return -1;
}
int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i< size; i++){
		scanf("%d", &arr[i]);
	}
	int val;
	printf("Enter the value you want to search\n");
	scanf("%d",&val);
	int result=binary_search(arr,size,val);
	printf("%d ",result);
	return 0;
}




//max_min
#include<stdio.h>

int find_max(int arr[],int size){
	int max=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
int find_min(int arr[],int size){
	int min=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	return min;
}
int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter the elements of the array: ");
	for(int i = 0; i< size; i++){
		scanf("%d", &arr[i]);
	}
	int max=find_max(arr,size);
	int min=find_min(arr,size);
	printf("max=%d min==%d",max,min);
	return 0;
}
