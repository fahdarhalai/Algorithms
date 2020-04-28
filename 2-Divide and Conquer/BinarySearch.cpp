#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IterativeBinarySearch(int* A, int n, int key, int* d){
	int l=0;
	int h=n-1;
	int mid;
	
	while(l<=h){
		(*d)++;
		mid=(l+h)/2;
		if(key == A[mid]){
			return mid;
		}
		
		if(key < A[mid]){
			h=mid-1;
		}else{
			l=mid+1;
		}
	}
	
	return -1;
}

int main(){
	int A[] = {3,6,8,12,14,17,25,29,31,36,42,47,53,55,62};
	int key = 62;
	int* d = (int*)calloc(1, sizeof(int));
	
	int keyInd = IterativeBinarySearch(A, 15, key, d);
	
	if(key != -1){
		printf("Key %d found at index: %d, after %d iterations.\n", key, keyInd, *d);
	}else{
		printf("Key not found!\n");
	}
	
	free(d);
	return 0;
}

