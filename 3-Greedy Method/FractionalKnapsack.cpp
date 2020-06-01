#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int index;
	int profit;
	int weight;
	float unit_profit;
} Item;

// Display the items
void display(Item A[], int n){
	for(int i=0; i<n; i++){
		printf("- Item %d :\n", A[i].index);
		printf("\tProfit = %d\n", A[i].profit);
		printf("\tWeight = %d\n", A[i].weight);
		printf("\tP/W = %.2f\n\n", A[i].unit_profit);
	}
}

// Fractional Knapsack
int* FractionalKnapsack(Item A[], int n, int Capacity){
	// Quantity of each items initialized to ZERO
	int *quantity = (int*)calloc(n, sizeof(int));
	
	// Sort A in decreasing order of unit profit
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(A[i].unit_profit < A[j].unit_profit){
				Item temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	
	int total_weight = 0;
	for(int i=0; i<n; i++){
		int w = 0;
		while(w < A[i].weight && total_weight < Capacity){
			quantity[A[i].index] += 1; // Increment quantity of item A[i].index
			w++;
			total_weight++;
		}
	}
	
	return quantity;
}

// Find total profit
float total_profit(Item A[], int* qty, int n){
	float total = 0;
	for(int i=0; i<n; i++){
		total += A[i].unit_profit * qty[A[i].index];
	}
	
	return total;
}

// Find total weight
float total_weight(int* qty, int n){
	float total = 0;
	for(int i=0; i<n; i++){
		total += qty[i];
	}
	
	return total;
}

void solution(Item A[], int* qty, int n){
	float total_p = total_profit(A, qty, n);
	float total_w = total_weight(qty, n);
	for(int i=0; i<n; i++){
		printf("- %d * Item(%d) = %.2f\n", qty[A[i].index], A[i].index, qty[A[i].index]*A[i].unit_profit);
	}
	
	printf("\nTotal profit = %.2f\n", total_p);
	printf("Total weight = %.2f\n", total_w);
}

int main(){
	int Capacity = 15; // Capacity of the knapsack
	int n = 7; // Number of items
	Item A[n]; // Array of items
	
	// Initialize Items
	A[0].index = 0;
	A[0].profit = 10;
	A[0].weight = 2;
	A[0].unit_profit = (float) A[0].profit / A[0].weight;
	
	A[1].index = 1;
	A[1].profit = 4;
	A[1].weight = 3;
	A[1].unit_profit = (float) A[1].profit / (float) A[1].weight;
	
	A[2].index = 2;
	A[2].profit = 15;
	A[2].weight = 5;
	A[2].unit_profit = (float) A[2].profit / (float) A[2].weight;
	
	A[3].index = 3;
	A[3].profit = 7;
	A[3].weight = 7;
	A[3].unit_profit = (float) A[3].profit / (float) A[3].weight;
	
	A[4].index = 4;
	A[4].profit = 6;
	A[4].weight = 1;
	A[4].unit_profit = (float) A[4].profit / (float) A[4].weight;
	
	A[5].index = 5;
	A[5].profit = 18;
	A[5].weight = 4;
	A[5].unit_profit = (float) A[5].profit / (float) A[5].weight;
	
	A[6].index = 6;
	A[6].profit = 3;
	A[6].weight = 1;
	A[6].unit_profit = (float) A[6].profit / (float) A[6].weight;
	// End intialization
	
	int* qty = FractionalKnapsack(A, n, Capacity); // Quantity of each item
	
	// Display items
	printf("Items in decreasing order of unit profit:\n");
	display(A, n);
	
	// Display the solution (quantity of each item)
	printf("Solution: \n");
	solution(A, qty, n);
	
	return 0;
}
