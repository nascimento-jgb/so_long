/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:30:26 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/02 17:46:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	plot_image(t_param *param, void **image, char *filepath)
{
	int	width;
	int	height;
	*image = mlx_xpm_file_to_image(param->mlx_ptr, filepath, &width, &height);
	if(!*image)
	{
		all_free(param);
		exit(0); // message about bad image generation
	}
}

void	all_free(t_param *param)
{
	int	aux;

	aux = 0;
	mlx_destroy_image(param->mlx_ptr, param->player);
	mlx_destroy_image(param->mlx_ptr, param->wall);
	mlx_destroy_image(param->mlx_ptr, param->collectable);
	mlx_destroy_image(param->mlx_ptr, param->ground);
	mlx_destroy_image(param->mlx_ptr, param->exit);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	while (param->map[aux++])
		free(param->map[aux]);
	free(param->map);
	//include msg about winning or failing the game
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == 13 && move_up(param))
		printf("%d/n", ++param->steps); //use ft_printf
	if (keycode == 1 && move_down(param))
		printf("%d/n", ++param->steps); //use ft_printf
	if (keycode == 0 && move_left(param))
		printf("%d/n", ++param->steps); //use ft_printf
	if (keycode == 2 && move_right(param))
		printf("%d/n", ++param->steps); //use ft_printf
	if (keycode == 53)
	{
		all_free(param);
		exit(0);
	} //exit and free all img
	return (0);
}
