/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:14:52 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 17:58:29 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	count_size(unsigned int nb)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*printf_itoa(unsigned int n)
{
	size_t	size;
	char	*str;

	size = count_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

int	func_u(unsigned int i)
{
	int	j;
	char			*str;

	j = 0;
	str = printf_itoa(i);
	if (str == NULL)
		return (0);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
	return (j);
}
