/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:27:54 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/02 15:31:21 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE 42

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;

	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, count * size);
	return (aux);
}

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (i < n)
		aux[i++] = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}

char	*ft_nextline(char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		aux[j++] = buff[i++];
	free(buff);
	return (aux);
}

char	*ft_readline(char *buff)
{
	char	*line;
	int		count;

	count = 0;
	if (!buff[count])
		return (NULL);
	while (buff[count] != '\n' && buff[count])
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (buff[count] != '\n' && buff[count])
	{
		line[count] = buff[count];
		count++;
	}
	if (buff[count] == '\n' && buff[count])
		line[count++] = '\n';
	return (line);
}

char	*ft_join_n_free(char *stash, char *rbuff)
{
	char	*aux;

	aux = ft_strjoin(stash, rbuff);
	free(stash);
	return (aux);
}

char	*file_read(int fd, char *stash)
{
	char	*read_buffer;
	int		bytes;

	if (!stash)
		stash = ft_calloc(1, 1);
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes] = 0;
		stash = ft_join_n_free(stash, read_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = file_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_readline(buff);
	buff = ft_nextline(buff);
	return (line);
}

// LIBFT

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
