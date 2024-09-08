/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRING_ARRAY_PRIVATE_H
# define STRING_ARRAY_PRIVATE_H

# include "string_array.h"
# include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s);

char		*get_string_array(t_str_array *array, int index);
int			len_string_array(t_str_array *array);
void		free_string_array(t_str_array *array);
t_str_array	*clone_string_array(t_str_array *array);
t_str_array	*map_string_array(t_str_array *array, char *(*f)(char *));
int			every_string_array(t_str_array *array, int (*f)(const char *));
t_i32_array	*parse_string_array(t_str_array *array);

t_str_array	*string_array_from(char **array);
t_str_array	*string_array_empty();

void		free_i32_array(t_i32_array *array);
t_i32_array	*create_i32_array(size_t size);

#endif //STRING_ARRAY_PRIVATE_H
