/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:27:54 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/04 17:09:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// LIBFTs

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 != '\0' && n > 0)
	{
		if (*p2 == '\0')
			return (1);
		if (*p2 > *p1)
			return (-1);
		if (*p1 > *p2)
			return (1);
		p1++;
		p2++;
		n--;
	}
	if (*p2 != '\0' && n > 0)
		return (-1);
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		lenght;
	char	*aux;

	lenght = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!aux)
		return (NULL);
	lenght = 0;
	while (str[lenght])
	{
		aux[lenght] = str[lenght];
		lenght++;
	}
	aux[lenght] = '\0';
	return (aux);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	len;

	len = ft_strlen(src);
	if (dst_size == 0)
		return (len);
	while (--dst_size > 0)
	{
		if (!*src)
			break ;
		*(dst++) = *(src++);
	}
	*dst = '\0';
	return (len);
}

static int	count_words(const char *str, const char limit)
{
	const char	*aux;
	int			counter;

	aux = str;
	counter = 0;
	while (*aux)
	{
		if (*aux != limit)
			if (aux == str || *(aux - 1) == limit)
				counter++;
		aux++;
	}
	return (counter);
}

static void	add_words(char **new, const char *str, char limit, int index)
{
	const char	*aux;
	const char	*start;

	aux = str;
	while (*aux)
	{
		if (*aux != limit)
		{
			if (aux == str || *(aux - 1) == limit)
			{
				start = aux;
				while (*aux && *aux != limit)
					aux++;
				if (count_words(aux, limit) > 0)
					add_words(new, aux, limit, index + 1);
				new[index] = (char *)malloc(aux - start + 1);
				if (new[index] != NULL)
					ft_strlcpy(new[index], start, aux - start + 1);
				return ;
			}
		}
		else
			aux++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	aux;

	if (s == NULL)
		return (NULL);
	aux = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * aux + 1);
	if (split == NULL)
		return (NULL);
	split[aux] = NULL;
	add_words(split, s, c, 0);
	return (split);
}

//GNL

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len + 1));
	if (!strjoin || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len] = 0;
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != c && *aux != 0)
		aux++;
	if (*aux == c)
		return (aux);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}

static void	ft_strcpy(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

static char	*ft_read(int fd, char *str, int ret, char *buf)
{
	char	*tmp;

	while (ret > 0 && str[ft_strlen(str) - 1] != '\n')
	{
		if (!*str)
			ft_strcpy(buf, str);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static int	ret;
	char		*str;
	static char	c[2];

	if (fd == -1 || read(fd, c, 0) == -1)
		return (NULL);
	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (ret == 0)
	{
		ret = read(fd, c, 1);
		c[ret] = '\0';
	}
	if (ret > 0 && c[0] != '\0')
		str = ft_read(fd, str, ret, c);
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}


