/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:02:34 by chpark            #+#    #+#             */
/*   Updated: 2022/04/20 17:13:18 by ojeongmin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	*arr;
	int	used_size;
}				t_list;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*command;
}				t_stacks;

/*
** push_swap.c
*/

int			main(int ac, char **av);
void		init_stack_a(t_stacks *stacks, int *src_arr, int size, char **str);
void		init_stack_b(t_stacks *stacks, int size, char **str);
int			free_stack(t_stacks *stacks);

/*
** setup.c
*/

t_stacks	*setup_stack(char **str);
int			*make_index_sort(int *arr, int size, char **str);
char		**av_to_string(char	**av, int ac);
int			ft_put_err(t_stacks *stacks, char *message, char **str, int ret);
int			count_stack_size(char **str);

/*
** setup_utils.c
*/

char		*ft_strjoin_push_swap(char *left_line, char *buff);
int			ft_atoi_push_swap(const char *nptr, char **str);
int			ft_sort_int_arr(int *tab, int size);
int			*index_preprocess(int *sorted, int *arr, int size);
int			check_dup_arr(int *arr, int size);

/*
** sort.c
*/

int			ft_sort(t_stacks *stack, int size);

/*
** ft_sort_three.c
*/

int			three_sort(t_stacks *stack);

/*
** ft_sort_four.c
*/

int			four_sort(t_stacks *stack);

/*
** ft_sort_five.c
*/

int			five_sort(t_stacks *stack);

/*
** ft_sort_utils.c
*/

int			is_sorted(t_list *a);
int			ft_diff(int s1, int s2);

/*
** utils.c
*/

int			ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s);
void		ft_putendl_fd(char *s, int fd);
int			*make_copy_arr(int *dest, int *src, int n);

/*
** utils2.c
*/

char		**ft_split(char const *s, char *c);

/*
** utils3.c
*/

char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_editstr(char *s, size_t n);
void		ft_str_free(char **str);

/*
** command_check.c
*/

int			check_command(t_stacks *stack, char *command);

/*
** command_check_utils.c
*/

int			check_command_s(t_stacks *stack, char *command, int n);
int			check_command_p(t_stacks *stack, char *command, int n);
int			check_command_ra(t_stacks *stack, int n);
int			check_command_rb(t_stacks *stack, int n);
int			check_command_rr(t_stacks *stack, char *command, int n);
/*
** command_push.c
*/

int			pa(t_stacks *stack);
int			pb(t_stacks *stack);

/*
** command_reverse_rotate.c
*/

int			reverse_rotate_mecro(t_list *a);
int			rra(t_stacks *stack);
int			rrb(t_stacks *stack);
int			rrr(t_stacks *stack);

/*
** command_rotate.c
*/

int			rotate_mecro(t_list *a);
int			ra(t_stacks *stack);
int			rb(t_stacks *stack);
int			rr(t_stacks *stack);

/*
** command_swap.c
*/

int			sa(t_stacks *stack);
int			sb(t_stacks *stack);
int			ss(t_stacks *stack);

#endif
