// Including User Defined Header file which contains all Macros, Preprocessor Directive and Function Declarations
#include "0_1_knapsack.h"

/*
 This function will perform below activities (0/1 Knapsack Problem - using below algorithms):
 1. Brute Force Algorithm
 2. Refined Algorithm of Dynamic Programming Approach
 3. Backtracking Algorithm
 4. Generate random number of Items, Profits and Weights between given range
 */
int main() {
    printf(RED"\n\n-------------------------- 0/1 Knapsack Problem __ NITESH MISHRA --------------------------\n"RST);

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

    printf(MAG"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"RST);
    printf(LGRN"Count of Items (randomly generated between 4 and 8)  -->   "RST"%d\n\n", items_count);
    printf(LGRN"Capacity of Knapsack [W = floor(0.6 * (weights sum)] -->   "RST"%d\n", knapsack_capacity);

    printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''");
    printf("\nSorted list of Items according to Profit per unit Weight (p/w) --> \n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"RST);
    for (i = 0; i < items_count; i++) {
        printf("\nITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d)\t;\tPROFIT/WEIGHT(%.2f)",
               items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight, items_list[i].profit_per_unit_weight);
    }
    printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"RST);

    printf(MAG"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"RST);

    printf(LBLU"\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*# START : BRUTE-FORCE ALGORITHM (0/1 Knapsack Problem) #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);
    // Function call to solve 0/1 Knapsack Problem using Brute-Force algorithm
    brute_force_algorithm(items_list);
    printf(LBLU"\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#  END : BRUTE-FORCE ALGORITHM (0/1 Knapsack Problem)  #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);

    printf(YLW"\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*# START : REFINED DYNAMIC PROGRAMMING (0/1 Knapsack Problem) #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);
    // Function call to solve 0/1 Knapsack Problem using Refined Dynamic Programming Algorithm
    refined_dynamic_programming_algorithm(items_list);
    printf(YLW"\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#  END : REFINED DYNAMIC PROGRAMMING (0/1 Knapsack Problem)  #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);

    printf(LMAG"\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*# START : BACKTRACKING ALGORITHM (0/1 Knapsack Problem)  #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);
    // Function call to solve 0/1 Knapsack Problem using Backtracking algorithm
    backtracking_algorithm(items_list);
    printf(LMAG"\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#  END : BACKTRACKING ALGORITHM (0/1 Knapsack Problem)   #*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n"RST);

    // Free Heap Memory
    free(items_list);

    printf(YLW"\n\n\nTHANK YOU for using my 0/1 Knapsack Program: \n"
                   "Solved using Brute-Force, Refined Dynamic Programming & Backtracking Algorithms.\n"
                   "                                                          ----- Nitesh Mishra !!"RST);
    printf(RED"\n------------------------------------------------------------------------------------------------------------------------\n\n"RST);
    return 0;
}

/*
 Implementation of Brute-Force Algorithm to solve 0/1 Knapsack problem
 */
int brute_force_algorithm(Item *items_list) {

    // Variable Declaration and Initialization
    int i, j, temp;
    int subset_cnt = 0, subset_items_cnt, subset_weight, subset_profit;
    int total_profit = 0, total_weight = 0, items[ITEM_COUNT_MAX], items_cnt = 0;
    Subset temp_subset;
    int subsets_count = (int) pow(2, items_count);

    Subset *subsets_list = malloc(subsets_count * sizeof(Subset));

    // Initialization of Subsets and Final Set arrays
    for (i = 0; i < subsets_count; i++) {
        for (j = 0; j < ITEM_COUNT_MAX; j++) {
            subsets_list[i].subset_items[j] = -1;
            items[j] = -1;
        }
    }

    // Preparation of all possible combinations of Items
    for (i = 0; i < subsets_count; i++) {
        subset_items_cnt = 0;
        subset_weight = 0;
        subset_profit = 0;
        for (j = 0; j < items_count; j++) {
            temp = (int) pow(2, j);
            if (temp & i) {
                subset_profit += items_list[j].item_profit;
                subset_weight += items_list[j].item_weight;
                subsets_list[subset_cnt].subset_items[subset_items_cnt] = j;
                subset_items_cnt++;
            }
        }
        subsets_list[subset_cnt].subset_profit = subset_profit;
        subsets_list[subset_cnt].subset_weight = subset_weight;
        subset_cnt++;
    }

    // Sorting of subsets according to respective profit/ benefit
    for (i = 0; i < subsets_count; i++) {
        for (j = i + 1; j < subsets_count; j++) {
            if (subsets_list[i].subset_profit < subsets_list[j].subset_profit) {
                temp_subset = subsets_list[i];
                subsets_list[i] = subsets_list[j];
                subsets_list[j] = temp_subset;
            }
        }
    }

    // Copying final values in respective variables
    for (i = 0; i < subsets_count; i++) {
        if (subsets_list[i].subset_weight <= knapsack_capacity) {
            for (j = 0; j < 8; j++) {
                if (subsets_list[i].subset_items[j] != -1) {
                    items[items_cnt] = subsets_list[i].subset_items[j];
                    items_cnt++;
                }
            }
            total_profit = subsets_list[i].subset_profit;
            total_weight = subsets_list[i].subset_weight;
            break;
        }
    }

    printf(GRN"\nFinal ITEMS in Knapsack  :->\n"RST);
    for (i = 0; i < ITEM_COUNT_MAX; i++) {
        if (items[i] != -1) {
            printf(CYN"\t\t\t    ITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d) \n"RST,
                   items_list[items[i]].item_name, items_list[items[i]].item_profit, items_list[items[i]].item_weight);
        }
    }
    printf(GRN"\nFinal PROFIT in Knapsack :-> "RST"\t$ %d\n", total_profit);
    printf(GRN"Final WEIGHT in Knapsack :-> "RST"\t%d\n", total_weight);

    // Free Heap Memory
    free(subsets_list);

    return 0;
}

/*
 Implementation of Refined Dynamic Programming Algorithm to solve 0/1 Knapsack problem
 */
int refined_dynamic_programming_algorithm(Item *items_list) {

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

    printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''");
    printf("\nADJACENCY MATRIX with required calculated elements --> \n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);
    display_matrix_elements(adjacency_matrix_B);
    printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);

    printf(GRN"\nFinal ITEMS in Knapsack  :->\n"RST);
    for (i = 0; i < items_count; i++) {
        if (flag[i] == 1) {
            printf(CYN"\t\t\t    ITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d) \n"RST,
                   items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight);
            weight = weight + items_list[i].item_weight;
        }
    }
    printf(GRN"\nFinal PROFIT in Knapsack :-> "RST"\t$ %d\n", adjacency_matrix_B[items_count][knapsack_capacity]);
    printf(GRN"Final WEIGHT in Knapsack :-> "RST"\t%d\n", weight);

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
 Implementation of Backtracking Algorithm to solve 0/1 Knapsack problem
 */
int backtracking_algorithm(Item *items_list) {

    // Variable Declaration and Initialization
    int i, include[ITEM_COUNT_MAX], final_weight = 0;
    Item temp_item;

    // Initializing best set
    for (i = 0; i < ITEM_COUNT_MAX; i++) {
        best_set[i] = -1;
    }

    printf(CYN"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''");
    printf("\nDepth First Search (DFS) Traversing Details --> \n");
    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);
    // Call for function Knapsack with initial values
    knapsack_backtracking(-1, 0, 0, include, items_list);
    printf(CYN"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n"RST);

    printf(GRN"\nFinal ITEMS in Knapsack  :->\n"RST);
    for (i = 0; i < ITEM_COUNT_MAX; i++) {
        if (best_set[i] == 1) {
            printf(CYN"\t\t\t    ITEM(%c)\t;\tPROFIT($%d)\t;\tWEIGHT(%d) \n"RST,
                   items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight);

            final_weight += items_list[i].item_weight;
        }
    }
    printf(GRN"\nFinal PROFIT in Knapsack :-> "RST"\t$ %d\n", max_profit);
    printf(GRN"Final WEIGHT in Knapsack :-> "RST"\t%d\n", final_weight);

    return 0;
}

/*
 Function to implement Backtracking Algorithm
 */
int knapsack_backtracking(int node_index, int node_profit, int node_weight, int *include, Item *items_list) {

    // Variable Declaration and Initialization
    int i;
    Item current_item;

    // Best possible solution saved in the global variables
    if (node_weight <= knapsack_capacity && node_profit > max_profit) {
        max_profit = node_profit;
        for (i = 0; i < items_count; i++) {
            best_set[i] = include[i];
        }
    }

    // Condition to check for promising node
    if (promising_node(node_index, node_profit, node_weight, items_list)) {
        current_item = items_list[node_index + 1];
        include[node_index + 1] = 1;
        knapsack_backtracking(node_index + 1, node_profit + current_item.item_profit, node_weight + current_item.item_weight, include, items_list);
        include[node_index + 1] = 0;
        knapsack_backtracking(node_index + 1, node_profit, node_weight, include, items_list);
    }

    return 0;
}

/*
 Function to check the condition for the promising node
 */
bool promising_node(int node_index, int node_profit, int node_weight, Item *items_list) {

    // Variable Declaration and Initialization
    int upper_bound = 0;

    // Condition - 1 (Node weight should not be greater than Overall Knapsack Capcity)
    if (node_weight >= knapsack_capacity) {
        printf("Profit --> $%-5d \t|\t Weight --> %-5d \t|\t Bound --> (Weight >= C = %d) \n", node_profit, node_weight, knapsack_capacity);
        return false;
    }

    // Condition - 2 (Upper Bound for the Node should be greater than the current Max Profit)
    upper_bound = knapsack_with_fraction(node_index + 1, node_weight, node_profit, items_list);

    printf("Profit --> $%-5d \t|\t Weight --> %-5d \t|\t Bound --> %-5d \n", node_profit, node_weight, upper_bound);

    return (upper_bound > max_profit);
}

/*
 Function to calculate the Upper Bound for the current Node using Knapsack with Fraction Algorithm
 */
int knapsack_with_fraction(int node_index, int node_weight, int node_profit, Item *items_list) {

    // Variable Declaration and Initialization
    int i, upper_bound = node_profit;
    Item current_item;


    // Logic to traverse items by items to calculate maximum profit gained using KFW2 algorithm
    while (node_weight < knapsack_capacity && node_index < items_count) {
        current_item = items_list[node_index];
        if (node_weight + current_item.item_weight <= knapsack_capacity) {
            node_weight = node_weight + current_item.item_weight;
            upper_bound = upper_bound + current_item.item_profit;
        } else {
            upper_bound = upper_bound + (knapsack_capacity - node_weight) * (current_item.item_profit / current_item.item_weight);
            node_weight = knapsack_capacity;
        }
        node_index++;
    }

    return upper_bound;
}