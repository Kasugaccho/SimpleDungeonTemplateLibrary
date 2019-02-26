#include "SimpleBiomeIsland.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int **dungeon, *dungeon_base_matrix;
	int y = 128, x = 128;
	int i, row, col;

	srand((unsigned int)time(NULL));

	dungeon = (int **)malloc(y * sizeof(int *));
	if (dungeon == NULL) return -1;
	dungeon_base_matrix = (int *)calloc(y * x, sizeof(int));
	if (dungeon_base_matrix == NULL) return -1;
	for (i = 0; i < y; ++i) {
		dungeon[i] = dungeon_base_matrix + i * x;
	}

	createSimpleBiomeIsland(dungeon, x, y, 50, 4);

	for (row = 1; row < y; ++row) {
		for (col = 1; col < x; ++col) {
			switch (dungeon[row][col])
			{
			case 0:
				printf("//");
				break;
			case 1:
				printf("##");
				break;
			case 2:
				printf("**");
				break;
			case 3:
				printf("++");
				break;
			}
		}
		printf("\n");
	}



	free(dungeon_base_matrix);
	free(dungeon);

	return 0;
}