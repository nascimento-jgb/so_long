/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:16:12 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/30 10:53:59 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

typedef struct s_img
{
	void *img_ptr;
	int *data;
	int width;
	int height;
	int bpp;
	int size_l;
	int endian;
}	t_img;

int main(void)
{
	t_mlx mlx;
	t_img img;
	int count_w;
	int count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "modifying loading");
	img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "./textures/wall_test.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	count_h = -1;
	while (++count_h < img.height)
	{
		count_w = -1;
		while (++count_w < (img.width/2))
		{
			if (count_w % 2)
				img.data[count_h * img.width + count_h] = 0xFFFFFF;
			else
				img.data[count_h * img.width + count_h] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 50, 50);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
