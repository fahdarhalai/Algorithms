#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int index;
	int profit;
	int deadline;
}Job;

void Sort(Job jobs[], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(jobs[i].profit < jobs[j].profit){
				Job temp = jobs[i];
				jobs[i] = jobs[j];
				jobs[j] = temp;
			}
		}
	}
}

void Display(Job jobs[], int n){
	
	printf("Index\t\t");
	for(int i=0; i<n; i++){
		printf("%d\t", jobs[i].index);
	}
	
	printf("\nProfit\t\t");
	for(int i=0; i<n; i++){
		printf("%d\t", jobs[i].profit);
	}
	
	printf("\nDeadline\t");
	for(int i=0; i<n; i++){
		printf("%d\t", jobs[i].deadline);
	}
	printf("\n");
}

int TotalProfit(Job jobs[], int n){
	int total = 0;
	for(int i=0; i<n; i++){
		total += jobs[i].profit;
	}
	
	return total;
}

int max_deadline(Job jobs[], int n){
	int Max = jobs[0].deadline;
	for(int i=1; i<n; i++){
		if(Max < jobs[i].deadline){
			Max = jobs[i].deadline;
		}
	}
	return Max;
}

Job* JobSequencing(Job jobs[], int n){
	Sort(jobs, n);
	int Max = max_deadline(jobs, n);
	Job *sequence = (Job*)malloc(sizeof(Job)*Max);
	
	for(int i=0; i<Max; i++){
		sequence[i].index = -1;
	}
	
	int Counter = 0;
	for(int i=0; i<n; i++){
		if(Counter == Max) break;
		int k = jobs[i].deadline - 1;
		if(sequence[k].index == -1){
			Counter++;
			sequence[k] = jobs[i];
		}else{
			for(int j=k-1; j>=0; j--){
				if(sequence[j].index == -1){
					Counter++;
					sequence[j] = jobs[i];
					break;
				}
			}
		}
	}
	
	return sequence;
}


int main(){
	int n = 7;
	Job J1, J2, J3, J4, J5, J6, J7;
	J1.index = 0;
	J1.profit = 35;
	J1.deadline = 3;
	
	J2.index = 1;
	J2.profit = 30;
	J2.deadline = 4;
	
	J3.index = 2;
	J3.profit = 25;
	J3.deadline = 4;
	
	J4.index = 3;
	J4.profit = 20;
	J4.deadline = 2;
	
	J5.index = 4;
	J5.profit = 15;
	J5.deadline = 3;
	
	J6.index = 5;
	J6.profit = 12;
	J6.deadline = 1;
	
	J7.index = 6;
	J7.profit = 5;
	J7.deadline = 2;
	
	Job jobs[] = {J2,J5,J1,J3,J7,J4,J6};
	printf("- ALL JOBS :\n");
	Display(jobs, n);
	
	printf("\n- JOB SCHEDULING :\n");
	Job *sequence = JobSequencing(jobs, n);
	Display(sequence, max_deadline(jobs, n));
	printf("\n=>Total Profit: %d\n", TotalProfit(sequence, max_deadline(jobs, n)));
	
	
	free(sequence);
	return 0;
}
