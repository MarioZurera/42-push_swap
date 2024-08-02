/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 03:28:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/wait.h>

enum e_error_code
{
	NO_CHILD_PROCESS = 10,
	MANY_FD_OPEN = 24,
	PERMISSION_DENIED = 126,
	COMMAND_NOT_FOUND = 127,
	NO_FILE_OR_DIR = 128
};

typedef struct  stack
{
    int             *list;
    unsigned int    size;
}   t_stack;

t_stack	parse_numbers(int argc, char **argv);

int		main(int argc, char **argv);

#endif /* PIPEX_H */