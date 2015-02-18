/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:18:55 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/01 15:19:02 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 512

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);

#endif
