/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:29:32 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/29 17:26:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-l mlx -framework OpenGL -framework AppKit

#include <string.h>
#include <stdlib.h>
#include "mlx.h"

//macros and structs
#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53

typedef struct	s_img
{
	void	*img_ptr;
	int 	*data;
	int 	bpp;
	int 	size_l;
	int 	endian;
}	t_img;

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		map[ROW][COL];
}t_game;

//auxiliary functions
void	minilibx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "game 2D");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

void	draw_pixel_tiles(t_game *game, int row, int col)
{
	int	tile_row;
	int	tile_col;

	row *= TILES;
	col *= TILES;

	tile_row = 0;
	while (tile_row < TILES)
	{
		tile_col = 0;
		while (tile_col < TILES)
		{
			if (tile_row == TILES - 1 || tile_col == TILES - 1)
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xb3b3b3;
			else
				game->img.data[(tile_row + row) * WIDTH + (tile_col + col)] = 0xFFFFFF;
			tile_col++;
		}
		tile_row++;
	}
}

void	draw_tiles(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				draw_pixel_tiles(game, row, col);
			col++;
		}
		row++;
	}

}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*auxdst;
	const char	*auxsrc;

	if (!dst && !src && n > 0)
		return (dst);
	auxdst = dst;
	auxsrc = src;
	while (n)
	{
		*auxdst++ = *auxsrc++;
		n--;
	}
	return (dst);
}

void	map_init(t_game *game)
{
	int src[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	/*{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},*/
	};
	ft_memcpy(game->map, src, sizeof(int) * ROW * COL);
	draw_tiles(game);
}

int	key_press(int keycode,  t_game game)
{
	if (keycode == KEYCODE_EXIT)
		exit(0);
	return(0);
}

int	close(t_game game)
{
	exit(0);
}

int	main(void)
{
	t_game	game;

	minilibx_init(&game);
	img_init(&game);
	map_init(&game);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, 0);
	mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, &close, &game);
	mlx_loop(game.mlx_ptr);
	return(0);
}
