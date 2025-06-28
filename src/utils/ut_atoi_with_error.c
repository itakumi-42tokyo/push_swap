/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_atoi_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:16:48 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 19:17:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// nullcheckは呼び出し元がするべきかな？
// check if nptr does'nt have string and any forbit sign and overflow underflow
int	ut_atoi_with_error(const char *nptr, bool *error)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ut_isspace(*nptr))
		nptr++;
	if (ut_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + *nptr - '0';
		if (sign == 1 && result > INT_MAX)
			return (*error = true, -1);
		if (sign == -1 && (sign * result) < INT_MIN)
			return (*error = true, -1);
		nptr++;
	}
	if (*nptr != '\0')
		return (*error = true, -1);
	return (sign * (int)result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char *argv = "123";
// 	bool		error = false;
// 	int	num = ut_atoi_with_error(argv, &error);
// 	printf("num: %d\n", num);
// 	return (0);
// }
