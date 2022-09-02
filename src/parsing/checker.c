/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:12:35 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/01 16:56:56 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int ft_is_digit(int c)
{
    if ((c >= '0' && c <= '9'))
        return (1);
    else   
        return (0);
}

int ft_isalnum(char *s)
{
    int i;
    
    i = 0;
    if (s[i] == '-')
        i++;
    while (s[i])
    {
        if (!ft_is_digit(s[i]))
            return (1);
        i++;
    }
    return (0);
}

int checker(int ac, char **av)
{
    int i;

    if (ac < 6)
    {   
        i = 1;
        while (av[i])
        {
            if (ft_is_digit(ft_atoi(av[i])) == 1)
                return (printf("Enter numbers only!!"), 0);
            i++;
        }
        i = 1;
        while (av[i])
        {
            if (atoi(av[i]) < 0)
                return (printf("Dont't enter negative numbers"), 0);
            else if (ft_atoi(av[i]) == 0)
                return (printf("Nothing should be 0"), 0);
            i++;
        }
    }
    return (0);
}