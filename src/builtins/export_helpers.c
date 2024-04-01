/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:53:29 by irivero-          #+#    #+#             */
/*   Updated: 2024/04/01 10:05:08 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	error_msg_export(char *var, char *val, char *message)
{
	ft_putstr_fd("minishell: export: `", 2);
	if (var)
		ft_putstr_fd(var, 2);
	ft_putstr_fd(val, 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

int	non_empty_str(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return (count);
	while (*arr)
	{
		if (**arr != '\0')
			count++;
		arr++;
	}
	return (count);
}

char	**empty_str(char **arr)
{
	int		count;
	char	**stripped_arr;
	int		i;

	count = non_empty_str(arr);
	stripped_arr = malloc(sizeof(char *) * (count + 1));
	if (!stripped_arr)
		return (NULL);
	i = 0;
	while (*arr)
	{
		if (**arr != '\0')
		{
			stripped_arr[i] = ft_strdup(*arr);
			i++;
		}
		arr++;
	}
	stripped_arr[i] = NULL;
	return (stripped_arr);
}

void	export_one(char **arr, t_list **env_list)
{
	char	*var;
	char	*val;
	char	*str;

	var = arr[0];
	val = arr[1];
	if (val == NULL)
		val = ft_strdup("");
	str = ft_strjoin(var, ft_strdup("="));
	str = ft_strjoin(str, val);
	unset_env_list(env_list, &var);
	ft_lstadd_back(env_list, ft_lstnew(str));
}