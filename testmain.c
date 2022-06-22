#include "tools.h"

void print_map(char **map)
{
	for (int i = 0; i < 13; i++)
		printf("%s\n", map[i]);
}

char **init_map(int row, int col)
{
	char **map;
	map = (char **)malloc(sizeof(char *) * row);
	for (int i = 0; i < 13; i++)
	{
		map[i] = (char *)malloc(sizeof(char) * col + 1);
		memset(map[i], '.',col);
		map[i][col] = '\0';
	}
	return (map);
}
int main ()
{
	char *map[] = {
		"...................................",
		"...................................",
		"......X.................X..........",
		"......X..................X.........",
		"......X...............XXXX.........",
		"...................................",
		"....................XXXXX..........",
		".........X.........................",
		".........XXX.......................",
		"..........X........................",
		"................XXXXX..............",
		"...................................",
		"...................................",
	};
	
	t_data data = {
		data.len = 35,
		data.mapsize = 13,
		data.map1 = map,
		data.map2 = init_map(data.mapsize, data.len)
	};
	
	gameoflife(&data);
}