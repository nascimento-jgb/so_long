/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:07:25 by joaonascime       #+#    #+#             */
/*   Updated: 2022/12/02 15:15:48 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

int main (void)
{
	void *mlx;
	void *win;
	void *img;

	int img_width;
	int	img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./sprites/soldiers.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	img = mlx_xpm_file_to_image(mlx, "./sprites/soldiers.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 40);
	img = mlx_xpm_file_to_image(mlx, "./sprites/soldiers.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 40, 0);
	img = mlx_xpm_file_to_image(mlx, "./sprites/down.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 40, 40);
	mlx_loop(mlx);
	return (0);
}
