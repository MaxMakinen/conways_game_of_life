#include "tools.h"

void	check_neighbours(t_data *data, int row, int col)
{
	int count = 0;
	int iRow = row - 1 * (row > 0); 
	int jCol = col - 1 * (col > 0);
	int endRow = row + 1 * (row < 12);
	int endCol = col + 1 * (col < 34);
	// printf("i: %d j: %d endi: %d endj: %d\n", iRow, jCol, endRow, endCol);

	for (int i = iRow; i <= endRow; i++)
	{
		for (int j = jCol; j <= endCol; j++)
		{
			if (data->map1[i][j] == 'X')
			{
				count++;
			}	
		}
	}
	if (data->map1[row][col] == 'X' && (count == 3 || count == 4))
		data->map2[row][col] = 'X';
	else if (data->map1[row][col] == '.' && count == 3)
		data->map2[row][col] = 'X';
}

char	**gameoflife(t_data *data)
{
	for (int row = 0; row < data->mapsize; row++)
	{
		for (int col = 0; col < data->len; col++)
			check_neighbours(data, row, col);
	}
	print_map(data->map2);
	return NULL;
}