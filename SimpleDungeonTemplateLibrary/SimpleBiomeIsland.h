#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C89_SIMPLE_BIOME_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C89_SIMPLE_BIOME_ISLAND
/*:::::----------::::::::::----------:::::
	 Dungeon Template Library
		  Made by Gaccho.
 This code is licensed under CC0.
	   wanotaitei@gmail.com
:::::----------::::::::::----------:::::*/

#include <stdlib.h>

void createSimpleBiomeIsland(int** matrix_, int x_, int y_, int max_value_, int type_) {

	int i, row, col;

	for (row = 1; row < y_ - 1; ++row) {
		for (col = 1; col < x_ - 1; ++col) {
			if (((int)(((double)rand() / ((double)RAND_MAX + 1)) * 2))) {
				matrix_[row][col] = ((int)(((double)rand() / ((double)RAND_MAX + 1)) * type_));
			}
		}
	}

	for (i = 0; i < max_value_; ++i) {
		for (row = 1; row < y_ - 1; ++row) {
			for (col = 1; col < x_ - 1; ++col) {
				if (matrix_[row][col - 1] && matrix_[row][col + 1] && matrix_[row - 1][col] && matrix_[row + 1][col]) {
					matrix_[row][col] = matrix_[row][col + 1];
				}
				else {
					switch (((int)(((double)rand() / ((double)RAND_MAX + 1)) * 4)))
					{
					case 0:
						matrix_[row][col] = matrix_[row][col - 1];
						break;
					case 1:
						matrix_[row][col] = matrix_[row][col + 1];
						break;
					case 2:
						matrix_[row][col] = matrix_[row - 1][col];
						break;
					case 3:
						matrix_[row][col] = matrix_[row + 1][col];
						break;
					}
				}
			}
		}
	}
}

#endif /*Included Dungeon Template Library*/