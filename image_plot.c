/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_plot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:16:16 by joaonascime       #+#    #+#             */
/*   Updated: 2022/12/04 12:59:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

#include <stdio.h>
#include "mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 200
# define IMG_HEIGHT 150

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp; //RGB value for each pixel in bits
	int		size_line; //each pixel is represented by 4 chars -> width x 4
	int		endian; //value 0 or 1 depending of the structure of the computer used
}	t_img;

typedef struct s_mlx
{
	void 	*mlx_ptr;
	void 	*win;
	t_img	img;
} 		t_mlx;

int	main(void)
{
	t_mlx mlx;
	int	count_w;
	int	count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	mlx.img.img_ptr=mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	mlx.img.data= (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_line, &mlx.img.endian);
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				mlx.img.data[count_h * IMG_WIDTH+ count_w] = 0xFFFFFF;
			else
				mlx.img.data[count_h * IMG_WIDTH + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0); //displays image at 0,0 coordinate
	mlx_loop(mlx.mlx_ptr);
	return(0);
}
