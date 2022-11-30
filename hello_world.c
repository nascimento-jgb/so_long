/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:05:11 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/30 10:53:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mlx.h"

typedef struct  data_s
{
    void    *ptr;
    void    *win;
}                 data_t;

int draw_line(void *ptr, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX; // 10
    double deltaY = endY - beginY; // 0
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    //  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
    deltaX /= pixels; // 1
    deltaY /= pixels; // 0
    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(ptr, win, pixelX, pixelY, 0xFFFFFF);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return (0);
}

int main(void)
{
    data_t        mlx;

    if ((mlx.ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((mlx.win = mlx_new_window(mlx.ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_pixel_put(mlx.ptr, mlx.win, 640/2, 480/2, 0xFFFFFF);
    draw_line(mlx.ptr, mlx.win, 640, 360, 0, 0, 0xFFFFFF);
    mlx_loop(mlx.ptr);
    return (EXIT_SUCCESS);
}
