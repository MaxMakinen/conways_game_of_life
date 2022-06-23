/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:42 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/23 16:01:23 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	init_data(t_data *data)
{
	int	count = 0;
	while (count < 0)
	{
		data->b[count] = 0;
		data->s[count] = 0;
		count++;
	}
	data->b_len = 0;
	data->s_len = 0;
	data->row = 0;
	data->col = 0;
	data->head = NULL;
	data->top = NULL;
}

void	std_rules(t_data *data)
{
	data->b[0] = 3;
	data->b_len = 1;
	data->s[0] = 2;
	data->s[1] = 3;
	data->s_len = 2;
}

void	print_map(t_data *data, char **map)
{
	int	row = 0;
	int	col = 0;

	while (row < data->row)
	{
		col = 0;
		while (col < data->col)
		{
			printf("%c", map[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	print_list(data->head);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		len;

	init_data(&data);
	if (ac == 3)
	{
		prep_map(av[1], &data);
		data.iterations = atoi(av[2]);
		std_rules(&data);
		len = data.col * data.row;
		while (data.iterations--)
		{
			gameoflife(&data);
			memcpy(data.pool1, data.pool2, len);
			memset(data.pool2, '.', (sizeof(char) * len));
			data.pool2[len] = '\0';
		}
		print_map(&data, data.map1);
		printf("\n");
	}
}
