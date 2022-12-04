/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:12:03 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/04 17:30:40 by jonascim         ###   ########.fr       */
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
	int		end_of_game;
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
static char		*get_data(int fd);
static t_param	*get_dimensions(t_param *param);
void			check_line(char *line, size_t lenght, size_t row);

//movement
static void 	update_image(t_param *game, char c);
int				moving_up(t_param *game);
int				moving_down(t_param *game);
int				moving_left(t_param *game);
int				moving_right(t_param *game);

//utils
void			plot_image(t_param *param, void **image, char *filepath);
int				key_press(int keycode, t_param *param);
int				all_free_exit(t_param *param);
void			all_free(t_param *param);
void			exit_message(char *msg, int i);

//extra utils
//GNL
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
static void	ft_strcpy(char *src, char *dst);
static char	*ft_read(int fd, char *str, int ret, char *buf);
char	*get_next_line(int fd);
//LIBFT
char	*ft_strdup(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
static int	count_words(const char *str, const char limit);
static void	add_words(char **new, const char *str, char limit, int index);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
#endif
