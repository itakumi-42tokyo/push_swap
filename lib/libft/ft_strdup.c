/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:49:44 by itakumi           #+#    #+#             */
/*   Updated: 2025/05/05 15:50:01 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	tmp = dest;
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (tmp);
}

// int	main(void)
// {
// 	char s[] = "tnaito";
// 	char *result = ft_strdup(s);
// 	printf("%s", result);
// 	return (0);
// }
