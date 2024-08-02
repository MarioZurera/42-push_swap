/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:52:05 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 18:02:39 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_count_words(const char *str)
{
    int count;
    
    count = 0;
    while (*str)
    {
        while (ft_isspace(*str))
            str++;
        if (*str)
            count++;
        while (*str && !ft_isspace(*str))
            str++;
    }
    return (count);
}