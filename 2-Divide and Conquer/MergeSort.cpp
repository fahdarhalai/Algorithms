#include <stdio.h>
#include <stdlib.h>

int* Merge(int* A, int* B, int n, int m){
	int* C = (int*)malloc(sizeof(int)*(n+m));
	int i=0;
	int j=0;
	int k=0;
	
	while(i<n and j<m){
		if(A[i] < B[j]){
			C[k++] = A[i++];
		}else{
			C[k++] = B[j++];
		}
	}
	
	for( ; i<n; i++){
		C[k++] = A[i];
	}
	
	for( ; j<m; j++){
		C[k++] = B[j];
	}
	
	return C;
}

int* MergeSort(int* A, int l, int h){
	int* res = (int*)malloc((h-l+1)*sizeof(int));
	
	if(l<h){
		int mid = (l+h)/2;
		int* X = MergeSort(A, l, mid);
		int* Y = MergeSort(A, mid+1, h);
		return Merge(X, Y, mid-l+1, h-mid);
	}
	
	res[0] = A[l];
	return res;
}

int main(){
	int A[] = {2,6,3,68,12,46,21,5,8,47,2,0,18,2,12,33,45,23,21,9,8,19,1292};
	int n = 23;
	
	int* B = MergeSort(A, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d ", B[i]);
	}
	
	return 0;
}
