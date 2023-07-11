/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:48:44 by rluiz             #+#    #+#             */
/*   Updated: 2023/06/09 17:29:09 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	**comp_helper(char *str, int i)
{
	char	**comp;

	comp = (char **)malloc(sizeof(char *) * 4);
	comp[0] = (char *)malloc(sizeof(char) * (i + 1));
	comp[1] = (char *)malloc(sizeof(char) * 3);
	comp[2] = (char *)malloc(sizeof(char) * (ft_strlen(str) - i - 1));
	comp[3] = NULL;
	ft_memset(comp[0], 0, i + 1);
	ft_memset(comp[1], 0, 3);
	ft_memset(comp[2], 0, ft_strlen(str) - i - 2);
	return (comp);
}

static char	**ft_spliti(char *str, int i)
{
	char	**comp;
	int		j;

	j = 0;
	comp = comp_helper(str, i);
	while (j < ft_strlen(str))
	{
		if ((j <= i - 1))
			comp[0][j] = str[j];
		else if ((j >= i) && (j <= i + 1))
			comp[1][j - i] = str[j];
		else if (j >= i + 2)
			comp[2][j - i - 2] = str[j];
		j++;
	}
	return (comp);
}

static void	split_helper(t_list *list)
{
	char	*cont;
	int		j;
	char	**new;
	char	*valid_flags;

	valid_flags = "cspdiuxX%";
	j = 0;
	cont = (char *)list->content;
	while ((cont[j] != '%') || (cont[j] == '%' && !ft_strchr(valid_flags, cont[j
					+ 1])))
		j++;
	new = ft_spliti(cont, j);
	j += 2;
	list->content = new[2];
	ft_lstadd_back(&list, ft_lstnew(new[0]));
	ft_lstadd_back(&list, ft_lstnew(new[1]));
	free(new);
	cont = (char *)list->content;
}

t_list	*ft_splitflags(char *src)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = creat_lst(src);
	i = 0;
	while (i++ < count_flags(src))
	{
		split_helper(list);
	}
	tmp = ft_lstnew(list->content);
	ft_lstadd_back(&list, tmp);
	list = list->next;
	return (list);
}
