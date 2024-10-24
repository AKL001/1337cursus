/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:05:14 by ablabib           #+#    #+#             */
/*   Updated: 2024/10/24 14:19:37 by ablabib          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}