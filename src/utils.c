/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:30:26 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/06 14:54:59 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	plot_image(t_param *param, void **image, char *filepath)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(param->mlx_ptr, filepath, &width, &height);
	if (!*image)
	{
		all_free(param);
		exit_message("ERROR: Image initialization failed!", 0);
	}
}

int	all_free_exit(t_param *param)
{
	all_free(param);
	exit(0);
}

void	all_free(t_param *param)
{
	int	aux;

	aux = -1;
	mlx_destroy_image(param->mlx_ptr, param->player);
	mlx_destroy_image(param->mlx_ptr, param->wall);
	mlx_destroy_image(param->mlx_ptr, param->collectable);
	mlx_destroy_image(param->mlx_ptr, param->ground);
	mlx_destroy_image(param->mlx_ptr, param->exit);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	while (param->map[++aux])
		free(param->map[aux]);
	free(param->map);
	if (param->end_of_game)
		printf("Congratulations! Your final score is: %d\n", ++param->steps);
}

int	key_press(int keycode, t_param *param)
{
	if ((keycode == 13 || keycode == 126) && moving_up(param))
		ft_printf("%d\n", ++param->steps);
	if ((keycode == 1 || keycode == 125) && moving_down(param))
		ft_printf("%d\n", ++param->steps);
	if ((keycode == 0 || keycode == 123) && moving_left(param))
		ft_printf("%d\n", ++param->steps);
	if ((keycode == 2 || keycode == 124) && moving_right(param))
		ft_printf("%d\n", ++param->steps);
	if (keycode == 53)
		all_free_exit(param);
	return (0);
}

void	exit_message(char *msg, int i)
{
	ft_putendl_fd(msg, 2);
	exit(i);
}
