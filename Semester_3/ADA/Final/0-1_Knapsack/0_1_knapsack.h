// Predefined Libraries used in program
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<memory.h>
#include<string.h>

// Constants to print, outputs in color format to the Console
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YLW "\x1B[33m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define RST "\x1B[0m"
#define LRED "\x1b[91m"
#define LGRN "\x1b[92m"
#define LYLW "\x1b[93m"
#define LBLU "\x1b[94m"
#define LMAG "\x1b[95m"
#define LCYN "\x1b[96m"

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

// Structure for Subset
typedef struct _Subset {
    int subset_items[ITEM_COUNT_MAX];
    int subset_profit;
    int subset_weight;
} Subset;

// Global Declaration
int items_count = 0;
int knapsack_capacity = 0;
int max_profit = 0;
int best_set[ITEM_COUNT_MAX];

// Function Declaration
int brute_force_algorithm(Item *items_list);

int refined_dynamic_programming_algorithm(Item *items_list);

int calc_matrix_B(int row_index, int column_index, int matrix_B[items_count + 1][knapsack_capacity + 1], Item *items_list);

int display_matrix_elements(int adjacency_matrix_B[items_count + 1][knapsack_capacity + 1]);

int backtracking_algorithm(Item *items_list);

int knapsack_backtracking(int node_index, int node_profit, int node_weight, int *include, Item *items_list);

bool promising_node(int node_index, int node_profit, int node_weight, Item *items_list);

int knapsack_with_fraction(int node_index, int node_weight, int node_profit, Item *items_list);