/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_in_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:05:51 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 11:05:51 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

t_list	*ptr_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

int	len_tab(t_list *list)
{
	int		len;

	len = 0;
	while (list->next != NULL)
	{
		list = list->next;
		len++;
	}
	return (len);
}

char	*ft_strdup_free(const char *str)
{
	int		isize;
	int		i;
	char	*dup;

	isize = ft_strlen(str);
	dup = (char *) malloc(isize + 1);
	if (! dup)
		return (NULL);
	dup[isize --] = '\0';
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i ++;
	}
	return (dup);
}

int	only_path(t_input *input)
{
	if (input->no[0] == 'N' && input->no[1] == 'O' && input->no[2] == ' ')
		input->no = ft_strdup_free(input->no + 3);
	else
		return (init_print_error("Error\nNO is not valid.\n"));
	if (input->so[0] == 'S' && input->so[1] == 'O' && input->so[2] == ' ')
		input->so = ft_strdup_free(input->so + 3);
	else
		return (init_print_error("Error\nSO is not valid.\n"));
	if (input->we[0] == 'W' && input->we[1] == 'E' && input->we[2] == ' ')
		input->we = ft_strdup_free(input->we + 3);
	else
		return (init_print_error("Error\nWE is not valid.\n"));
	if (input->ea[0] == 'E' && input->ea[1] == 'A' && input->ea[2] == ' ')
		input->ea = ft_strdup_free(input->ea + 3);
	else
		return (init_print_error("Error\nEA is not valid.\n"));
	return (0);
}

int only_nbr(t_input *input)
{
	if (input->f[0] == 'F' && input->f[1] == ' ')
		input->f = ft_strdup_free(input->f + 2);
	else
		return (init_print_error("Error\nF is not valid.\n"));
	if (input->c[0] == 'C' && input->c[1] == ' ')
		input->c = ft_strdup_free(input->c + 2);
	else
		return (init_print_error("Error\nC is not valid.\n"));
	return (0);
}