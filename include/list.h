/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:13:35 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/30 20:46:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
// malloc free

# include <stddef.h>
// NULL

#include <stdbool.h>
// bool

// 双方向リストはノードの数をもたせたほうが良いのか？
// リストを消す場合、残りのノードが１つになったときはnext,prevを自分自身を指すようにするのか？

// 合計のコストも書いておくべきか？
typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_cost;

typedef struct s_root
{
	struct s_list	*sentinel;
	int				node_len;
}	t_root;

typedef struct s_list
{
	bool			lis;
	int				number;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_singl
{
	char		*operation;
	struct s_singl	*next;
}	t_singl;

t_list	*ut_create_node_back(t_root *root, int data);
t_list	*ut_create_node(t_root *root, int data);
t_root	*ut_create_root(void);
t_list	*ut_create_first_node(t_root *linked_list, int data);
void	cdll_add_back(t_root *lst, t_list *new);
void	cdll_add_front(t_list **lst, t_list *new);
void	cdll_clear(t_root **lst, void (*del)(t_list*));
void	cdll_delone(t_list *lst);
void	cdll_iter(t_list *lst, void (*f)(int));
t_list	*cdll_last(t_root *linked_list);
t_list	*cdll_new(int num);
int		cdll_size(t_list *lst);
void    lst_add_back(t_singl **head_node, t_singl *new_node);
t_singl	*lst_last(t_singl *head_node);
t_singl *lst_new(char *data);
void	lst_all(t_singl **head_node, char *data);
void	lst_clear(t_singl **singl);

#endif
