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

int RecursiveBinarySearch(int* A, int l, int h, int key, int* d){
	(*d)++;
	if(l == h){
		if(A[l] == key){
			return l;
		}else{
			return -1;
		}
	}else{
		int mid = (l+h)/2;
		if(key == A[mid]){
			return mid;
		}
		if(key < A[mid]){
			h = mid-1;
		}else{
			l = mid+1;
		}
		return RecursiveBinarySearch(A, l, h, key, d);
	}
}

int main(){
	int A[] = {3,6,8,12,14,17,25,29,31,36,42,47,53,55,62};
	int key = 53;
	int* d = (int*)calloc(1, sizeof(int));
	
	int keyIndexIterative = IterativeBinarySearch(A, 15, key, d);
	printf("-- Iterative Binary Search: \n");
	if(key != -1){
		printf("Key %d found at index: %d, after %d iterations.\n", key, keyIndexIterative, *d);
	}else{
		printf("Key not found after %d iterations!\n", *d);
	}
	
	*d = 0;
	int keyIndexReucursive = RecursiveBinarySearch(A, 0, 14, key, d);
	printf("-- Recursive Binary Search :\n");
	if(key != -1){
		printf("Key %d found at index: %d, after %d iterations.\n", key, keyIndexReucursive, *d);
	}else{
		printf("Key not found after %d iterations!\n", *d);
	}
	
	free(d);
	return 0;
}

