/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:51:44 by ggiertzu          #+#    #+#             */
/*   Updated: 2024/04/11 02:39:11 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_node	*pipe_cmd(t_token **left, t_token **right, t_list *envir)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node -> ntype = N_PIPE;
	node -> left = parse_exe(left, envir);
	node -> right = parse_pipe(right, envir);
	return (node);
}

// returns pipe node with two children or exec node with one child
t_node	*parse_pipe(t_token **toklist, t_list *envir)
{
	t_node	*cmd;
	t_token	*token;

	token = *toklist;
	if (!token)
		return (NULL);
	while (token && token -> type != PIPE)
		token = token -> next;
	if (token && token -> type == PIPE)
		cmd = pipe_cmd(toklist, &(token -> next), envir);
	else
		cmd = parse_exe(toklist, envir);
	return (cmd);
}
