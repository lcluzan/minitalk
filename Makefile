# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcluzan <lcluzan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 16:28:04 by lcluzan           #+#    #+#              #
#    Updated: 2024/11/03 15:16:30 by lcluzan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= client
NAMESVR			= server
NAMEBONUS		= client_bonus
NAMESVRBONUS	= server_bonus

SHELL			=	/bin/bash



CC				=	cc
CFLAGS			=	-g -Wall -Wextra -Werror

LIBFT_DIR		=	libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))


all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@echo "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c includes/*.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(MLX) :
	@make --no-print-directory -C $(MLX_DIR)

clean :
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@make clean --no-print-directory -C $(MLX_DIR)
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -rf $(LIBFT)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
