/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:22:47 by etregoni          #+#    #+#             */
/*   Updated: 2017/03/10 01:45:02 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && n > 0)
	{
		if (*s1++ != *s2++)
			return (0);
		n--;
	}
	if (*s1 != *s2 && n > 0)
		return (0);
	return (1);
}
