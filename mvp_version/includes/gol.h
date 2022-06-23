/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:49 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/23 15:21:19 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H

# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>

typedef struct s_list
{
	int	row;
	int	col;
	struct s_list *next;
	struct s_list *prev;
} t_list;

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
void	read_map(FILE *file, t_data *data);
void	init_map(t_data *data, int len);

void	gameoflife(t_data *data);
t_list	*get_stack_end(t_list *list);
t_list	*stack_pop(t_list *list);
t_list	*stack_add(t_list *list, int row, int col);

void	print_map(t_data *data, char **map);
void	gameoflife(t_data *data);

#endif
