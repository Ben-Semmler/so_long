/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:16:21 by bsemmler          #+#    #+#             */
/*   Updated: 2021/09/27 19:05:10 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*store_line(int fd, char *buf, char *result);
int		fill_buffer(int fd, char *buf, int *finished, int result_len);
char	*create_new_result(char *result, char *buf, int blen, int result_len);
int		string_len(char *s);

char	*get_next_line(int fd)
{
	char	*result;
	char	*buf;

	result = malloc(1);
	buf = malloc(BUFFER_SIZE);
	result[0] = 0;
	return (store_line(fd, buf, result));
}

char	*store_line(int fd, char *buf, char *result)
{
	int		blen;
	int		result_len;
	int		finished;
	char	*new_result;

	finished = 0;
	result_len = string_len(result);
	blen = fill_buffer(fd, buf, &finished, result_len);
	if (blen == -1)
	{
		free(buf);
		free(result);
		return (NULL);
	}
	new_result = create_new_result(result, buf, blen, result_len);
	free(result);
	if (finished == 1)
	{
		free(buf);
		return (new_result);
	}
	return (store_line(fd, buf, new_result));
}

int	fill_buffer(int fd, char *buf, int *finished, int result_len)
{
	int	read_return;
	int	bpos;

	bpos = 0;
	while (*finished == 0 && bpos < BUFFER_SIZE)
	{
		read_return = read(fd, &buf[bpos], 1);
		if (read_return == -1)
			return (-1);
		if (read_return == 0)
		{
			if (result_len == 0 && bpos == 0)
				return (-1);
			bpos--;
			*finished = 1;
		}
		if (buf[bpos] == '\n' || buf[bpos] == 0)
			*finished = 1;
		bpos++;
	}
	return (bpos);
}

char	*create_new_result(char *result, char *buf, int blen, int result_len)
{
	char	*new_result;
	int		pos;

	new_result = malloc (result_len + blen + 1);
	pos = 0;
	while (result[pos])
	{
		new_result[pos] = result[pos];
		pos++;
	}
	while (pos < result_len + blen)
	{
		new_result[pos] = buf[pos - result_len];
		pos++;
	}
	new_result[pos] = 0;
	return (new_result);
}

int	string_len(char *s)
{
	int	pos;

	pos = 0;
	while (s[pos] != 0)
		pos++;
	return (pos);
}
