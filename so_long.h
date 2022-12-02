/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:12:03 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/02 15:31:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	void	*player;
	void	*wall;
	void	*collectable;
	void	*exit;
	void	*ground;
	int		c;
	int		e;
	int		p;
	int		steps;
}	t_param;

//render game
static void		init_base(t_param *game);
static void		init_img(t_param *game);
static void		init_item(t_param *game, void *element, int i, int j);
int				init_map(t_param *game);
void			render_game(t_param *game);

//check map
void			check_map(t_param *param);
static void		check_elements(t_param *param);
static void		check_borders(t_param *param);

//read map
void			open_map(char *argv, t_param *param);
static char		get_data(int fd);
static t_param	*get_dimensions(t_param *param);
void			check_line(char *line, size_t lenght, size_t row);

//utils
void			plot_image(t_param *param, void **image, char *filepath);
int				key_press(int keycode, t_param *param);
void			all_free(t_param *param);
#endif
