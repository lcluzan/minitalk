/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:01:48 by lcluzan           #+#    #+#             */
/*   Updated: 2024/11/03 17:10:34 by lcluzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <unistd.h>

void	ft_putstr_fd(const char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);


#endif
