#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<memory.h>
#include<string.h>

#include<iostream>
using namespace std;

void knapsack_Dynamic(int w[], int p[], int n, int W){
	int **P = new int*[n+1];

	for(int i=0; i<=n; i++)
		P[i] = new int[W+1];

	bool **keep = new bool*[n];

	for(int i=0; i<n; i++)
		keep[i] = new bool[W];

	for(int j=0; j<=W; j++) P[0][j] = 0;

	for(int i=1; i<=n; i++)
		for(int j=0; j<=W; j++){
			if(j>= w[i-1] && (p[i-1]+P[i-1][j-w[i-1]] > P[i-1][j])){
				P[i][j] = p[i-1] + P[i-1][j-w[i-1]];  keep[i-1][j-1]=true;
			}else{
				P[i][j] = P[i-1][j]; keep[i-1][j-1] = false;
			}
		}
	
	cout << "\nMatrix P\n";
	for(int i=0; i<=n; i++){
		for(int j=0; j<=W; j++)
			cout << P[i][j] << "\t";
		cout<<"\n";
	}

	cout<<"\nMatrix keep\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<W; j++)
			cout << keep[i][j] << "\t";
		cout << "\n";
	}

	int k=W;
	cout<<"\nOptimal set = {";
	for(int i=n; i>=1; i--){
		if(keep[i-1][k-1] == true) {
			cout<<"item-"<<i <<", ";
			k = k - w[i-1];
		}
	}
	cout<<"\b\b}\nMax. Profit = " << P[n][W];
}


/*
 Function to display adjacency_matrix_B Matrix elements on the console output
 */
int display_matrix_elements(int adjacency_matrix_B[items_count + 1][knapsack_capacity + 1]) {
    for (int p = 0; p < (items_count + 1); p++) {
        for (int q = 0; q < (knapsack_capacity + 1); q++) {
            if (adjacency_matrix_B[p][q] == -1) {
                printf("%-3d ", 0);
            } else {
                printf("%-3d ", adjacency_matrix_B[p][q]);
            }
        }
        printf("\n");
    }

    return 0;
}

/*
 Implementation of Refined Dynamic Programming Algorithm to solve 0/1 Knapsack problem
 */
int refined_dynamic_programming_algorithm(int items_count, ) {

    // Variable Declaration and Initialization
    int i, j, temp_p, temp_w, flag[items_count], weight = 0;

    // Adjacency Matrix Initialization [ Size --> (n + 1) * (W + 1) ]
    int adjacency_matrix_B[items_count + 1][knapsack_capacity + 1];
    for (i = 0; i < (items_count + 1); i++) {
        for (j = 0; j < (knapsack_capacity + 1); j++) {
            if (i == 0 || j == 0) {
                adjacency_matrix_B[i][j] = 0;
            } else {
                adjacency_matrix_B[i][j] = -1;
            }
        }
    }

    // Call for function in order to calculate required elements of Adjacency Matrix
    calc_matrix_B(items_count, knapsack_capacity, adjacency_matrix_B, items_list);


    // Logic to find considered Items for constructing Adjacency Matrix
    for (temp_p = items_count, temp_w = knapsack_capacity; temp_w > 0 && temp_p > 0; temp_p--) {
        if (adjacency_matrix_B[temp_p][temp_w] != adjacency_matrix_B[temp_p - 1][temp_w]) {
            flag[temp_p - 1] = 1;
            temp_w = temp_w - items_list[temp_p - 1].item_weight;
        }
    }

    // printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''");
    // printf("\nADJACENCY MATRIX with required calculated elements --> \n");
    // printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);
    display_matrix_elements(adjacency_matrix_B);
    // printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);

    // printf(GRN"\nFinal ITEMS in Knapsack  :->\n"RST);
    for (i = 0; i < items_count; i++) {
        if (flag[i] == 1) {
            // printf(CYN"\t\t\t    ITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d) \n"RST,
            //        items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight);
            weight = weight + items_list[i].item_weight;
        }
    }
    // printf(GRN"\nFinal PROFIT in Knapsack :-> "RST"\t$ %d\n", adjacency_matrix_B[items_count][knapsack_capacity]);
    // printf(GRN"Final WEIGHT in Knapsack :-> "RST"\t%d\n", weight);

    return 0;
}

// n^2 => 0,1,4,9,16,25,36,49,64
// 2^n => 1,2,4,8,16,32,64,128

int main(){
	int w[] = {5, 4, 6, 3};
	int p[] = {10, 40, 30, 50};
	int n = 4, W = 10;
	knapsack_Dynamic(w, p, n, W);
	return 0;
}
