# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kishino <kishino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 18:08:11 by kishino           #+#    #+#              #
#    Updated: 2024/09/18 18:37:09 by kishino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

lib_name="libft.a"

cc -c -Wall -Werror -Wextra *.c
ar rc $lib_name *.o
ranlib $lib_name
rm *.o