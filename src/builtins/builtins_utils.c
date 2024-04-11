/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:02:46 by irivero-          #+#    #+#             */
/*   Updated: 2024/04/11 23:00:48 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_start_valid(unsigned char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	else
		return (0);
}

int	is_char_valid(char *var)
{
	int	i;

	i = 0;
	if (!var || !*var || (!ft_isalpha((unsigned char)var[0]) && var[0] != '_'))
		return (1);
	i++;
	while (var[i])
	{
		if (!(ft_isalnum((unsigned char)var[i]) || var[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

char	*remove_one_quote_set(char *str)
{
	size_t	end;

	end = ft_strlen(str) - 1;
	if (str[0] == '\'' && str[end] == '\'')
		str = ft_strtrim(str, "\'");
	else if (str[0] == '\"' && str[end] == '\"')
		str = ft_strtrim(str, "\"");
	return (str);
}

int	get_arg_count(char **argv)
{
	int	len;

	len = 0;
	if (!argv)
		return (len);
	while (argv[len])
		len ++;
	return (len);
}

void	free_arr(char **env, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(env[i]);
		env[i] = NULL;
		i ++;
	}
	free(env);
	env = NULL;
}
