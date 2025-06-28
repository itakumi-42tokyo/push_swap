/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_errormsg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:50:30 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/25 19:43:06 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_errormsg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
