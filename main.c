/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:48:51 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/30 16:11:54 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(char *argv)
{
	int	i;
	while (argv[i] && argv[i] != '.')
		i++;
	if (!ft_strncmp(argv + i, ".ber", 4))
		return (0);
	return (1);
}

static t_param	*init_param(t_param *param)
{
	param->mlx_ptr = NULL;
	param->win_ptr = NULL;
	param->img_ptr = NULL;
	param->map = NULL;
	param->width = 0;
	param->height = 0;
	param->player_x = 0;
	param->player_y = 0;
	param->player = NULL;
	param->wall = NULL;
	param->collectable = NULL;
	param->exit = NULL;
	param->ground = NULL;
	param->c = 0;
	param->e = 0;
	param->p = 0;
	param->steps = 0;
}

int	main(int argc, char **argv)
{
	t_param *param;

	if (argc != 2)
		exit(0); // print exit error
	if (!check(argv[1]))
		exit(0); // print exit error
	param = (t_param *)malloc(sizeof(t_param));
	param = init_param(param); //initializing parameters
	open_map(argv[1], param);
	render_game(param); //rendering function in anotehr file
	return(0);
}
