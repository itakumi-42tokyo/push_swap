/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:14:27 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 14:29:27 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../lib/libft/libft.h"

// 1.　数字以外の文字が入っている状態を検知する（INT＿MAX MINのものも弾く）
// 2. 重複している場合やすでにソート済みのものを弾く
// 焦らずにこの関数はエラーチェックのみに仕様
// 数字は最大でも　INT＿MAX個しか来ないと仮定して良い。
// なぜなら、私は"引数に" 5 5 5" 5　みたいなものに対応させないから。
// しかし、int_maxこの配列を宣言するのに安全性はあるのか
// 配列を作らないなら、この場でlistを作ったほうが良いな
//　座標圧縮するのかどうか
// 現在何を求めているのか

// 今回は重複を探すためだけにハッシュテーブルを使うのは
// 必要性がないと思うので、ソートで検査する

int	check_duplication(int *numbers, int low, int high)
{
	int	i;

	quick_sort(numbers, low, high);
	i = 0;
	while (i < high)
	{
		if (numbers[i] == numbers[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_sorted(int *numbers, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (numbers[i] >= numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*check_error(int argc, char *argv[])
{
	int		i;
	bool	error;
	int		*numbers;

	i = 0;
	error = false;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (numbers == NULL)
		return (NULL);
	while (*argv)
	{
		numbers[i] = ut_atoi_with_error(*argv, &error);
		if (error)
		{
			free(numbers);
			return (NULL);
		}
		i++;
		argv++;
	}
	if (check_sorted(numbers, argc - 1) != 0)
	{
		free(numbers);
		exit (EXIT_SUCCESS);
	}
	if (check_duplication(numbers, 0, argc - 2) != 0)
		return (free(numbers), NULL);
	return (numbers);
}
