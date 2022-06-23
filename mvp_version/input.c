/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:37:02 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/23 12:14:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	init_map(t_data *data, int len)
{
	int		counter = 0;
	char	*temp1;
	char	*temp2;
	// printf("col: %d\n", len);

	data->pool1 = (char *)malloc(sizeof(char) * len);
	bzero(data->pool1, (sizeof(char) * len));
	data->pool2 = (char *)malloc(sizeof(char) * len);
	memset(data->pool2, '.', (sizeof(char) * len));
	data->pool2[len] = '\0';
	data->map1 = (char **)malloc(sizeof(char *) * data->row);
	data->map2 = (char **)malloc(sizeof(char *) * data->row);
	temp1 = data->pool1;
	temp2 = data->pool2;
	while (counter < data->row)
	{
		*(data->map1 + counter) = temp1;
		temp1 += data->col;
		*(data->map2 + counter) = temp2;
		temp2 += data->col;
		counter++;
	}
}

void	read_map(int fd, t_data *data)
{
	char	c;
	int		row = 0;
	int		col = 0;

	while (row < data->row)
	{
		col = 0;
		while (col < data->col + 1)
		{
			if (read(fd, &c, 1) == -1)
			{
				dprintf(2, "Read ERROR\n");
				exit(1);
			}
			if (c == 'x' || c == 'X')
				data->map1[row][col] = 'X';
			if (c == '.')
				data->map1[row][col] = '.';
			col++;
		}
		row++;
	}
}

void	prep_map(char *filename, t_data *data)
{
	int		fd = 0;
	int		first = 1;
	int		check = 0;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Open ERROR\n");
		exit(1);
	}
	check = read(fd, &c, 1);
	while(check > 0)
	{
		if (c == '\n')
		{
			data->row++;
			first = 0;
		}
		if (first == 1)
			data->col++;
		if (c == '\0')
			break;
		check = read(fd, &c, 1);
	}
	if (check == -1)
	{
		dprintf(2, "Read ERROR\n");
		exit(1);
	}
	init_map(data, (data->col * data->row));
	if (close(fd) == -1)
	{
		dprintf(2, "Close ERROR\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Open ERROR\n");
		exit(1);
	}
	read_map(fd, data);
	if (close(fd) == -1)
	{
		dprintf(2, "Close ERROR\n");
		exit(1);
	}
}
