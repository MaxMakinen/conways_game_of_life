/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:49 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/22 20:27:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

typedef struct s_data
{
	int		b[10];
	int		s[10];
	int		b_len;
	int		s_len;
	int		row;
	int		col;
	int		iterations;
	char	*pool1;
	char	*pool2;
	char	**map1;
	char	**map2;
}	t_data;

void	prep_map(char *filename, t_data *data);
void	read_map(int fd, t_data *data);
void	init_map(t_data *data, int len);
char	**gameoflife(t_data *data);
