/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:20:03 by ldinaut           #+#    #+#             */
/*   Updated: 2021/12/09 15:06:52 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putd(int n, int fd)
{
	int	i;

	i = ft_countnb(n);
	ft_putnbr_fd(n, fd);
	return (i);
}
