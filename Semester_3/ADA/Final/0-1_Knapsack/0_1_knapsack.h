// Predefined Libraries used in program
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<memory.h>
#include<string.h>

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

int refined_dynamic_programming_algorithm(Item *items_list);

int calc_matrix_B(int row_index, int column_index, int matrix_B[items_count + 1][knapsack_capacity + 1], Item *items_list);

int display_matrix_elements(int adjacency_matrix_B[items_count + 1][knapsack_capacity + 1]);
