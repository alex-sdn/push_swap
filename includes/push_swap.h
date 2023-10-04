/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:33 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:15:11 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	top_a;
	int	top_b;
	int	size;
}		t_stack;

/*  Libft  */
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

/*  main  */
int		main(int ac, char **av);
t_stack	*create_stx_mult(int ac, char **av);
t_stack	*create_stx_2(char **args);
void	*free_exit(t_stack *stx, int i);
void	free_args(char **args);

/*  Verify if arguments are correct  */
int		check_format(int ac, char **av, int i);
int		check_duplicates(t_stack *stx);
int		check_int_max(t_stack *stx, int ac, char **av, char **args);
int		check_int_max_2(t_stack *stx, char **args);
int		no_zero_strlen(char *s);

/*  Stack operations */
void	sa(t_stack *stx);
void	sb(t_stack *stx);
void	ss(t_stack *stx);
void	pa(t_stack *stx);
void	pb(t_stack *stx);
void	ra(t_stack *stx);
void	rb(t_stack *stx);
void	rr(t_stack *stx);
void	rra(t_stack *stx);
void	rrb(t_stack *stx);
void	rrr(t_stack *stx);

/*  Sorting algorithm  */
void	sort_algo(t_stack *stx, int lowest);
void	partition_a(t_stack *stx, int lowest);
void	partition_a_2(t_stack *stx, int limit);
int		partition_b(t_stack *stx);

/*  Utils for sorting algo  */
int		check_sorted(t_stack *stx);
int		check_sorted_b(t_stack *stx);
int		get_median_a(t_stack *stx, int pos_lowest);
int		get_median_b(t_stack *stx);
int		get_lowest_a(t_stack *stx, int pos_lowest);
int		get_lowest_b(t_stack *stx);
int		get_next_up(t_stack *stx, int nbr, int limit);
int		get_next_up_b(t_stack *stx, int nbr);
int		get_highest_a(t_stack *stx);
void	fix_order(t_stack *stx, int pos_lowest);

/*  Optimized sorting for partitioned stack  */
void	sort_rotate_5(t_stack *stx, int pos_lowest);
void	sort_rotate_5_solo(t_stack *stx);
int		push_3(t_stack *stx);
int		push_3_small(t_stack *stx, int size);

#endif
