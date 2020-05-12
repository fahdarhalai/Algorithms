#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findDim(int n){
	int k = log(n) / log(2);
	int N = pow(2, k);
	
	while(n > N){
		N = pow(2, ++k);
	}
	
	return N;
}

int* fill(int* A, int n, int N){
	int* newA = (int*)calloc(N*N, sizeof(int));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			newA[i*N+j] = A[i*n+j];
		}
	}
	
	return newA;
}

int* MatrixResize(int* A, int n, int* N){
	*N = findDim(n);
	
	if(*N != n){
		A = fill(A, n, *N);
	}
	
	return A;
}

int* assignMatrix(int* A, int iA, int jA, int p, int n){
	int* R = (int*)malloc(sizeof(int)*p*p);
	
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			R[i*p+j] = A[(i+iA)*n+(j+jA)];
		}
	}
	
	return R;
}

int* sumMatrix(int* X, int* Y, int n){
	int* R = (int*)malloc(sizeof(int)*n*n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			R[i*n+j] = X[i*n+j] + Y[i*n+j];
		}
	}
	return R;
}

int* subMatrix(int* X, int* Y, int n){
	int* R = (int*)malloc(sizeof(int)*n*n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			R[i*n+j] = X[i*n+j] - Y[i*n+j];
		}
	}
	return R;
}

void groupMatrix(int* C, int* X, int iX, int jX, int p, int N){
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			C[(i+iX)*N+(j+jX)] = X[i*p+j];
		}
	}
}

int* Strassen(int* A, int* B, int N){
	int* C = (int*)calloc(N*N, sizeof(int));
	
	if(N == 2){
		C[0] = A[0]*B[0] + A[1]*B[2];
		C[1] = A[0]*B[1] + A[1]*B[3];
		C[2] = A[2]*B[0] + A[3]*B[2];
		C[3] = A[2]*B[1] + A[3]*B[3];
	}else{
		int p = N/2;
		
		int* A11 = assignMatrix(A, 0, 0, p, N);
		int* A12 = assignMatrix(A, 0, p, p, N);
		int* A21 = assignMatrix(A, p, 0, p, N);
		int* A22 = assignMatrix(A, p, p, p, N);

		int* B11 = assignMatrix(B, 0, 0, p, N);
		int* B12 = assignMatrix(B, 0, p, p, N);
		int* B21 = assignMatrix(B, p, 0, p, N);
		int* B22 = assignMatrix(B, p, p, p, N);	
		
		int* M1 = Strassen(sumMatrix(A11, A22, p), sumMatrix(B11, B22, p), p);
		int* M2 = Strassen(sumMatrix(A21, A22, p), B11, p);
		int* M3 = Strassen(A11, subMatrix(B12, B22, p), p);
		int* M4 = Strassen(A22, subMatrix(B21, B11, p), p);
		int* M5 = Strassen(sumMatrix(A11, A12, p), B22, p);
		int* M6 = Strassen(subMatrix(A21, A11, p), sumMatrix(B11, B12, p), p);
		int* M7 = Strassen(subMatrix(A12, A22, p), sumMatrix(B21, B22, p), p);
		
		groupMatrix(C, sumMatrix(subMatrix(sumMatrix(M1, M4, p), M5, p), M7, p), 0, 0, p, N);
		groupMatrix(C, sumMatrix(M3, M5, p), 0, p, p, N);
		groupMatrix(C, sumMatrix(M2, M4, p), p, 0, p, N);
		groupMatrix(C, sumMatrix(sumMatrix(subMatrix(M1, M2, p), M3, p), M6, p), p, p, p, N);
	}
	
	return C;
}

int* StrassenMatrixMult(int* A, int* B, int n, int* N){
	int* newA = MatrixResize(A, n, N);
	int* newB = MatrixResize(B, n, N); 

	int* C = Strassen(newA, newB, *N);
	return C;
}

void showMatrix(int* A, int n, int N){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", A[i*N+j]);
		}
		printf("\n");
	}
}

int main(){
	int n = 10;
	int A[] = {6,1,8,9,21,6,2,6,7,8,
			   2,63,8,3,2,1,2,4,3,2,
			   0,52,7,9,2,1,2,7,1,11,
			   12,2,0,8,4,88,3,5,2,1,
			   1,7,5,5,9,4,1,11,2,7,
			   0,52,7,9,2,1,2,7,1,11,
			   0,52,7,9,2,1,2,7,1,11,
			   1,7,5,5,9,4,1,11,2,7,
			   6,1,8,9,21,6,2,6,7,8,
			   2,63,8,3,2,1,2,4,3,2};
			   	   
	int B[] = {1,5,4,2,7,6,1,11,2,7,
			   8,5,3,8,9,22,11,5,3,2,
			   1,22,11,24,3,88,3,22,7,3,
			   5,15,12,4,6,12,4,7,5,0,
			   42,3,6,0,8,22,1,0,9,7,
			   5,15,12,4,6,12,4,7,5,0,
			   42,3,6,0,8,22,1,0,9,7,
			   1,22,11,24,3,88,3,22,7,3,
			   1,5,4,2,7,6,1,11,2,7,
			   8,5,3,8,9,22,11,5,3,2};
	
	int* N = (int*)calloc(1, sizeof(int));
	int* C = StrassenMatrixMult(A, B, n, N);
	
	showMatrix(C, n, *N);
	
	return 0;
}



