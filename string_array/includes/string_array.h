/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H

# include <stdlib.h>

typedef struct s_str_array t_str_array;
typedef struct s_i32_array t_i32_array;

struct s_str_array {
	const char	**strings;
	char		*(*get)(t_str_array *, int);
	int			(*len)(t_str_array *);
	void		(*free)(t_str_array *);
	t_str_array	*(*clone)(t_str_array *);
	t_str_array	*(*map)(t_str_array *, char *(*f)(char *));
	int			(*every)(t_str_array *, int (*f)(const char *));

	/**
	 * Transform a t_str_array into a t_i32_array, freeing the original list.
	 */
	t_i32_array	*(*parse)(t_str_array *);
};

struct s_i32_array {
	int		*list;
	int		size;
	void	(*free)(t_i32_array *);
};

t_str_array	*string_array_from(char **array);
t_str_array	*string_array_from_const(char **array);
t_str_array	*string_array_empty();
t_i32_array	*create_i32_array(size_t size);

#endif //STRING_ARRAY_H
