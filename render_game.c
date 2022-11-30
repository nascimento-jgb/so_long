/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:50:27 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/30 16:23:35 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_base(t_param *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 40, game->height * 40, "Game");
	game->img_ptr = mlx_new_image(game->mlx_ptr, game->width * 40, game->height * 40);
	if (game->mlx_ptr == 0 || game->win_ptr == 0 || game->img_ptr == 0)
	{
		all_free(game);
		exit(0); //print message about error generating window
	}
}

static void	init_img(t_param *game)
{
	plot_image(game, &game->player, "./textures/player.xpm");
	plot_image(game, &game->wall, "./textures/wall.xpm");
	plot_image(game, &game->collectable, "./textures/collectable.xpm");
	plot_image(game, &game->ground, "./textures/ground.xpm");
	plot_image(game, &game->exit, "./textures/exit.xpm");
}

static void	init_item(t_param *game, void *element, int i, int j)
{
	if (element == game->player)
	{
		game->player_x = i;
		game->player_y = j;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, element, i*40, j*40);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, element, i*40, j*40);
}

int init_map(t_param *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i++])
	{
		while (game->map[i][j++])
		{
			if (game->map[i][j] == "1")
				init_item(game, game->wall, i, j);
			if (game->map[i][j] == "0")
				init_item(game, game->ground, i, j);
			if (game->map[i][j] == "P")
				init_item(game, game->player, i, j);
			if (game->map[i][j] == "C")
				init_item(game, game->collectable, i, j);
			if (game->map[i][j] == "E")
				init_item(game, game->exit, i, j);
		}
	}
	return (0);
}

void	render_game(t_param *game)
{
	init_base(game);
	init_image(game);
	init_map(game);
	mlx_hook(game->win_ptr, 2, 1L<<0, key_press, game); // keypress
	mlx_hook(game->win_ptr, 9, 1L<<21, init_map, game); // map generation
	mlx_loop(game->mlx_ptr);
}
