/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:46:56 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/29 16:16:44 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> //exit
#include "mlx.h"

#define X_EVENT_KEY_PRESS 2 //mlx_event
#define X_EVENT_KEY_RELEASE 3 //x_event

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

typedef struct s_param
{
	int x;
	int y;
}	t_param;

void param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_A)
		param->y--;
	else if (keycode == KEY_D)
		param->y++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("(x,y): (%d, %d)\n", param->x, param->y);
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	t_param param;

	mlx_ptr = mlx_init();
	param_init(&param);
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "Hello World");
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx_ptr);
	return(0);
}
