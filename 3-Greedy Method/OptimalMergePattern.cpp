#include <stdio.h>
#include <stdlib.h>

// Merging two arrays
int* Merge(int A[], int B[]){
	int a = A[0]; // The size of array A is stored in A[0]
	int b = B[0]; // The size of array B is stored in B[0]
	int *C = (int*)malloc(sizeof(int)*(a+b+1)); // Actual size = Effective size(a+b) + one for storing the Effective size
	C[0] = a+b; // Effective size
	
	int i=1, j=1, k=1;
	while(i<=a && j<=b){
		if(A[i] <= B[j]){
			C[k] = A[i];
			i++;
		}else{
			C[k] = B[j];
			j++;
		}
		k++;
	}
	
	while(i<=a){
		C[k] = A[i];
		i++;
		k++;
	}
	
	while(j<=b){
		C[k] = B[j];
		j++;
		k++;
	}
	
	return C;
}

// Sort the array of N arrays by their sizes in ASC order
void Sort(int *Arrays[], int N){
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(Arrays[i][0] > Arrays[j][0]){
				int *temp = Arrays[i];
				Arrays[i] = Arrays[j];
				Arrays[j] = temp;
			}
		}
	}
}

int* OptimalMerge(int *Arrays[], int N){
	Sort(Arrays, N);
	int **list = (int**)calloc(N-1, sizeof(int*));
	int i = 0, j = 0, n = N-1;
	
	list[j++] = Merge(Arrays[0], Arrays[1]);
	for(int k=2; k<N; k++){
		list[j++] = Arrays[k];
	}
	Sort(list, n);
	
	while(n > 1){	
		list[0] = Merge(list[0], list[1]);
		
		j = 1;
		for(int k=2; k<n; k++){
			list[j] = list[k];
			j++;
		}
		n--;
		Sort(list, n);
	}
	
	return list[0];
}

int main(){
	/**
		NOTE: All of the arrays that should be merged need to store their sizes
			  as C doesn't have a way to retrieve array size, we devote the element
			  at index 0 to be the effective size of the array.
			  The actual size of the array is always equal to the effective size + 1.
	**/
	
	
	int N = 4; // Number of arrays to merge
	
	int A1[] = {6, 1, 5, 9, 13, 14, 15}; // A1[0] is the effective size of A1 while A1[0]+1 is the actual size
	int A2[] = {5, 2, 6, 10, 12, 16};
	int A3[] = {2, 3, 7};
	int A4[] = {3, 4, 8, 11};

	int *Arrays[N] = {A1, A2, A3, A4}; // Array of N arrays
	
	// Finding the total size of the merged arrays
	int M = 0;
	for(int i=0; i<N; i++){
		M += Arrays[i][0];
	}
	
	// Retrieving the merged array
	int *R = OptimalMerge(Arrays, N);
	for(int i=1; i<=M; i++){
		printf("%d ", R[i]);
	}
	
	return 0;
}
