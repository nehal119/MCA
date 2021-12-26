#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ITEM_COUNT_MIN 4
#define ITEM_COUNT_MAX 8

typedef struct _Item {
  char item_name;
  int item_profit;
  int item_weight;
  float profit_per_unit_weight;
}
Item;

int items_count = 4;
int knapsack_capacity = 0;

int calc_matrix(int row_index, int column_index, int matrix_B[items_count + 1][knapsack_capacity + 1], Item * items_list) {
  int profit_temp_1, profit_temp_2;
  Item item_temp;
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
      profit_temp_1 = calc_matrix(row_index - 1, column_index - item_temp.item_weight, matrix_B, items_list);
      profit_temp_2 = calc_matrix(row_index - 1, column_index, matrix_B, items_list);

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

int refined_knapsack(Item * items_list) {
  int i, j, temp_p, temp_w, flag[items_count], weight = 0;

  // Initialize matrix
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

  calc_matrix(items_count, knapsack_capacity, adjacency_matrix_B, items_list);

  for (temp_p = items_count, temp_w = knapsack_capacity; temp_w > 0 && temp_p > 0; temp_p--) {
    if (adjacency_matrix_B[temp_p][temp_w] != adjacency_matrix_B[temp_p - 1][temp_w]) {
      flag[temp_p - 1] = 1;
      temp_w = temp_w - items_list[temp_p - 1].item_weight;
    }
  }

  printf("\nITEMS in Knapsack: \n\n");
  for (i = 0; i < items_count; i++) {
    if (flag[i] == 1) {
      printf("\t    ITEM(%c)\t ----------- \tPROFIT($%d)\t ----------- \tWEIGHT(%d) \n",
        items_list[i].item_name, items_list[i].item_profit, items_list[i].item_weight);
      weight = weight + items_list[i].item_weight;
    }
  }
  printf("\nTotal Profit in Knapsack: ""$%d\n", adjacency_matrix_B[items_count][knapsack_capacity]);
  printf("Total Weight in Knapsack: ""%d\n", weight);

  return 0;
}

int main() {
  int i, j;
  float profit_by_weight;
  Item temp_item;

  while (items_count < ITEM_COUNT_MIN || items_count > ITEM_COUNT_MAX) {
    items_count = (ITEM_COUNT_MIN + (rand() % ITEM_COUNT_MAX));
  }

  Item * items_list = malloc(items_count * sizeof(Item));

  int w[] = {5, 4, 6, 3};
  int p[] = {10, 40, 30, 50};

  for (i = 0; i < items_count; i++) {
    profit_by_weight = (float) p[i] / w[i];

    items_list[i].item_name = (char) i + 65;
    items_list[i].item_profit = p[i];
    items_list[i].item_weight = w[i];
    items_list[i].profit_per_unit_weight = profit_by_weight;
  }

  // Sort Items according to profit per unit weight
  for (i = 0; i < items_count; i++) {
    for (j = i + 1; j < items_count; j++) {
      if (items_list[i].profit_per_unit_weight < items_list[j].profit_per_unit_weight) {
        temp_item = items_list[i];
        items_list[i] = items_list[j];
        items_list[j] = temp_item;
      }
    }
  }

  for (i = 0; i < items_count; i++) {
    knapsack_capacity = knapsack_capacity + items_list[i].item_weight;
  }

  knapsack_capacity = (int) floor(0.6 * knapsack_capacity);

  refined_knapsack(items_list);

  return 0;
}