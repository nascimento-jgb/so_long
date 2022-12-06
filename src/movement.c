/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:36:22 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/06 14:55:20 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_image(t_param *game, char c)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player);
	if (c == 'w')
		plot_image(game, &game->player, "./textures/up.xpm");
	if (c == 's')
		plot_image(game, &game->player, "./textures/down.xpm");
	if (c == 'a')
		plot_image(game, &game->player, "./textures/left.xpm");
	if (c == 'd')
		plot_image(game, &game->player, "./textures/right.xpm");
}

int	moving_up(t_param *game)
{
	int	x;
	int	y;

	game->player_y--;
	x = game->player_x;
	y = game->player_y;
	update_image(game, 'w');
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->c--;
		game->map[y][x] = 'P';
		game->map[y + 1][x] = '0';
		init_map(game);
		return (1);
	}
	if (game->map[y][x] == 'E' && game->c == 0)
	{
		game->map[y + 1][x] = '0';
		game->end_of_game = 1;
		all_free_exit(game);
	}
	game->player_y++;
	init_map(game);
	return (0);
}

int	moving_down(t_param *game)
{
	int	x;
	int	y;

	game->player_y++;
	x = game->player_x;
	y = game->player_y;
	update_image(game, 's');
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->c--;
		game->map[y][x] = 'P';
		game->map[y - 1][x] = '0';
		init_map(game);
		return (1);
	}
	if (game->map[y][x] == 'E' && game->c == 0)
	{
		game->map[y - 1][x] = '0';
		game->end_of_game = 1;
		all_free_exit(game);
	}
	game->player_y--;
	init_map(game);
	return (0);
}

int	moving_left(t_param *game)
{
	int	x;
	int	y;

	game->player_x--;
	x = game->player_x;
	y = game->player_y;
	update_image(game, 'a');
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->c--;
		game->map[y][x] = 'P';
		game->map[y][x + 1] = '0';
		init_map(game);
		return (1);
	}
	if (game->map[y][x] == 'E' && game->c == 0)
	{
		game->map[y][x + 1] = '0';
		game->end_of_game = 1;
		all_free_exit(game);
	}
	game->player_x++;
	init_map(game);
	return (0);
}

int	moving_right(t_param *game)
{
	int	x;
	int	y;

	game->player_x++;
	x = game->player_x;
	y = game->player_y;
	update_image(game, 'd');
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->c--;
		game->map[y][x] = 'P';
		game->map[y][x - 1] = '0';
		init_map(game);
		return (1);
	}
	if (game->map[y][x] == 'E' && game->c == 0)
	{
		game->map[y][x - 1] = '0';
		game->end_of_game = 1;
		all_free_exit(game);
	}
	game->player_x--;
	init_map(game);
	return (0);
}
