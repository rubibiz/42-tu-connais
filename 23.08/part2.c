/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:12:41 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 17:57:59 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	func_d(int i)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_itoa(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	return (j);
}

int	func_i(int i)
{
	int		j;
	char	*str;

	j = 0;
	str = ft_itoa(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	return (j);
}
