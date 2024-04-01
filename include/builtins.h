/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:03:57 by irivero-          #+#    #+#             */
/*   Updated: 2024/04/01 10:04:35 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "expander.h"
# include "parser.h"
# include "tokenizer.h"
# include "exec_b.h"
# include "../libft/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>

extern int	g_exit_status;

//cd
void	our_cd(char **av, t_list *env);
//echo
int		echo_helper(char **av, char *c, int *i);
void	our_echo(char **av);
//exit
void	exit_command(char **av);
//export

void 	export_builtin(char **argv, t_list **env_list);
//export helpers
void	error_msg_export(char *var, char *val, char *message);
int		non_empty_str(char **arr);
char	**empty_str(char **arr);
void	export_one(char **arr, t_list **env_list);
//pwd
void	if_pflag_is_one(char *path);
char	*our_pwd(char **av, int pflag);
//unset
void	lst_rm(t_list **lst, int i);
void	unset_env_list(t_list **env_list, char **target_key);

//utils
int		is_start_valid(unsigned char c);
int		is_char_valid(char *var);
char	*remove_one_quote_set(char *str);
int		get_arg_count(char **argv);
void	free_arr(char **env, int len);

#endif
