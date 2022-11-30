/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:50:45 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/30 16:11:51 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_borders(t_param *param)
{
	int	aux;

	aux = 0;
	while (param->map[0][aux++])
	{
		if (param->map[0][aux] != 1 || param->map[param->height][aux] != 1)
			exit(0); //print message about invalid border
	}
	aux = 0;
	while (param->map[aux++][0])
	{
		if (param->map[aux][0] != 1)
			exit(0); //print message about invalid border
	}
	aux = 0;
	while (param->map[aux++][param->width])
	{
		if (param->map[aux][param->height] != 1)
			exit(0); //print message about invalid border
	}
}

static void	check_elements(t_param *param)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (param->map[i++])
	{
		j = 0;
		while (param->map[i][j++])
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
		exit(0); //print exit erro by invalid ammount of players
	if (param->c == 0)
		exit(0); //print exit erro by invalid ammount of collectables
	if (param->e != 1)
		exit(0); //print exit erro by invalid ammount of exits
}

void	check_map(t_param *param)
{
	check_elements(param);
	check_border(param);
}
