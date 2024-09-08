/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:26:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:26:00 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_space(char *str)
{
	char	*result;

	result = ft_strtrim(str, " \n\r\v\f\t");
	free(str);
	return (result);
}
