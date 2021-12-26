// Predefined Libraries used in program
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<memory.h>
#include<string.h>
#include <math.h>

// Constants used in the program
#define ITEM_COUNT_MIN 4
#define ITEM_COUNT_MAX 8
#define ITEM_PROFIT_MIN 10
#define ITEM_PROFIT_MAX 30
#define ITEM_WEIGHT_MIN 5
#define ITEM_WEIGHT_MAX 20

// Structure for Item
typedef struct _Item {
    char item_name;
    int item_profit;
    int item_weight;
    float profit_per_unit_weight;
} Item;

// Global Declaration
int items_count = 0;
int knapsack_capacity = 0;
int max_profit = 0;
int best_set[ITEM_COUNT_MAX];

int refined_knapsack(Item *items_list);

int calc_matrix_B(int row_index, int column_index, int matrix_B[items_count + 1][knapsack_capacity + 1], Item *items_list);

/*
 Implementation of Refined Dynamic Programming Algorithm to solve 0/1 Knapsack problem
 */
int refined_knapsack(Item *items_list) {

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

    printf("\nITEMS in Knapsack  :->\n");
    for (i = 0; i < items_count; i++) {
        if (flag[i] == 1) {
            printf("\t\t\t    ITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d) \n",
                   items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight);
            weight = weight + items_list[i].item_weight;
        }
    }
    printf("\nPROFIT in Knapsack :-> ""\t$ %d\n", adjacency_matrix_B[items_count][knapsack_capacity]);
    printf("WEIGHT in Knapsack :-> ""\t%d\n", weight);

    return 0;
}

/*
 This function is recursively called to calculate just the required elements in Adjacency Matrix
 */
int calc_matrix_B(int row_index, int column_index, int matrix_B[items_count + 1][knapsack_capacity + 1], Item *items_list) {

    // Variable Declaration and Initialization
    int profit_temp_1, profit_temp_2;
    Item item_temp;

    // Logic for recursive call to calculate required elements of Adjacency Matrix
    if (column_index >= 0) {
        if (row_index == 1 || matrix_B[row_index][column_index] != -1) {
            item_temp = items_list[row_index - 1];
            profit_temp_1 = matrix_B[row_index - 1][column_index - item_temp.item_weight];
            profit_temp_2 = matrix_B[row_index - 1][column_index];

            if ((item_temp.item_weight <= column_index) && (profit_temp_1 + item_temp.item_profit > profit_temp_2)) {
                matrix_B[row_index][column_index] = profit_temp_1 + item_temp.item_profit;
            } else {
                matrix_B[row_index][column_index] = profit_temp_2;
            }
            return matrix_B[row_index][column_index];
        } else {
            item_temp = items_list[row_index - 1];
            profit_temp_1 = calc_matrix_B(row_index - 1, column_index - item_temp.item_weight, matrix_B, items_list);
            profit_temp_2 = calc_matrix_B(row_index - 1, column_index, matrix_B, items_list);

            if ((item_temp.item_weight <= column_index) && (profit_temp_1 + item_temp.item_profit > profit_temp_2)) {
                matrix_B[row_index][column_index] = profit_temp_1 + item_temp.item_profit;
            } else {
                matrix_B[row_index][column_index] = profit_temp_2;
            }
            return matrix_B[row_index][column_index];
        }
    }

    return 0;
}

int main() {
    // Variable Declaration and Initialization
    int i, j, profit, weight;
    float profit_by_weight;
    Item temp_item;

    // Logic to initialize Random Number Generator as per time stamp so that rand() generates different random numbers
    srand((unsigned int) time(NULL));

    // Random generation for number of available Items
    while (items_count < ITEM_COUNT_MIN || items_count > ITEM_COUNT_MAX) {
        items_count = (ITEM_COUNT_MIN + (rand() % ITEM_COUNT_MAX));
    }

    // Initialization of structures
    Item *items_list = malloc(items_count * sizeof(Item));

    // Random generation for Profits and Weights for each items
    for (i = 0; i < items_count; i++) {
        profit = 0;
        weight = 0;
        while (profit < ITEM_PROFIT_MIN || profit > ITEM_PROFIT_MAX) {
            profit = (ITEM_PROFIT_MIN + (rand() % ITEM_PROFIT_MAX));
        }
        while (weight < ITEM_WEIGHT_MIN || weight > ITEM_WEIGHT_MAX) {
            weight = (ITEM_WEIGHT_MIN + (rand() % ITEM_WEIGHT_MAX));
        }

        profit_by_weight = (float) profit / weight;

        items_list[i].item_name = (char) i + 65;
        items_list[i].item_profit = profit;
        items_list[i].item_weight = weight;
        items_list[i].profit_per_unit_weight = profit_by_weight;
    }

    // Sorting list of Items according to Profit per unit Weight (p/w)
    for (i = 0; i < items_count; i++) {
        for (j = i + 1; j < items_count; j++) {
            if (items_list[i].profit_per_unit_weight < items_list[j].profit_per_unit_weight) {
                temp_item = items_list[i];
                items_list[i] = items_list[j];
                items_list[j] = temp_item;
            }
        }
    }

    // Formula to calculate overall Knapsack Capacity
    for (i = 0; i < items_count; i++) {
        knapsack_capacity = knapsack_capacity + items_list[i].item_weight;
    }

    knapsack_capacity = (int) floor(0.6 * knapsack_capacity);

    refined_knapsack(items_list);

    return 0;
}