#include "knights_tour.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 // board size

bool move_is_possible(size_t move_id, int x, int y, board_t visited) {
  // make an attempt move
  x += MOVES_X[move_id];
  y += MOVES_Y[move_id];

  // whether the new position is inside the board, if not return false
  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
    return false;
  }

  // whether the new position is visited, if so return false
  if (visited[x][y] == 1) {
    return false;
  }

  return true;
}

unsigned int tour_greedy(size_t start_x, size_t start_y) {
  // initialize the total number of moves
  size_t counter_moves = 0;

  // initialize the current position
  size_t current_x = start_x;
  size_t current_y = start_y;

  board_t visited = {0}; // initialize a board to mark moves
  visited[current_x][current_y] = 1;

  // initialize the very first attempt move
  size_t move_id = 0;

  while (1) {
    if (move_is_possible(move_id, current_x, current_y, visited) == 1) {
      current_x += MOVES_X[move_id];
      current_y += MOVES_Y[move_id];
      counter_moves++;
      move_id = 0;
      visited[current_x][current_y] = 1;
    } else if (move_id < 8) {
      move_id++;
    } else {
      return counter_moves;
    }
  }
}

void greedy_tour_from_each_square() {
  for (size_t row = 0; row < SIZE; row++) {
    for (size_t col = 0; col < SIZE; col++) {
      printf("%3u", tour_greedy(row, col));
    }
    printf("\n");
  }
}