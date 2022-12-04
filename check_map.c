/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:50:45 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/04 17:23:11 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_borders(t_param *param)
{
	int	aux;

	aux = -1;
	while (param->map[0][++aux])
	{
		if (param->map[0][aux] != '1')
			exit_message("ERROR: Invalid border!", 0);
	}
	aux = -1;
	while (++aux < param->height)
	{
		if (param->map[aux][0] != '1' || param->map[aux][param->width -1] != '1')
			exit_message("ERROR: Invalid border!",0);
	}
	aux = -1;
	while (param->map[param->height][++aux])
	{
		if (param->map[param->height][aux] != '1')
			exit_message("ERROR: Invalid border!", 0);
	}
}

static void	check_elements(t_param *param)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			if (param->map[i][j] == 'P')
				param->p++;
			if (param->map[i][j] == 'C')
				param->c++;
			if (param->map[i][j] == 'E')
				param->e++;
		}
	}
	if (param->p != 1)
		exit_message("ERROR: Invalid ammount of players!", 0);
	if (param->c == 0)
		exit_message("ERROR: Invalid ammount of collectable itens!", 0);
	if (param->e != 1)
		exit_message("ERROR: Invalid ammount of exits!", 0);
}

void	check_map(t_param *param)
{
	check_borders(param);
	check_elements(param);
}
