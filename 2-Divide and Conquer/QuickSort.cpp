#include <stdio.h>
#include <stdlib.h>


void swap(int* A, int i, int j){
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

int partition(int* A, int l, int h){
	int pivot = A[l];
	int i=l;
	int j=h;
	
	while(i < j){
		do{
			i++;
		}while(A[i] <= pivot && i<h);
		
		do{
			j--;
		}while(A[j] >= pivot && j>l);
		
		if(i<j){
			swap(A, i, j);
		}
	}
	
	swap(A, l, j);
	
	return j;
}

void QuickSort(int* A, int l, int h){
	if(l < h){
		int j = partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j+1, h);
	}
}

int main(){
	int len = 11;
	int A[] = {10, 16, 8, 7, 12, 15, 6, 18, 3, 9, 5};
	
	QuickSort(A, 0, len);
	
	for(int i=0; i<len; i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}
