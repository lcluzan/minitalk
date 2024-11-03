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

SERVER_NAME			=	server
CLIENT_NAME			=	client
SHELL				=	/bin/bash

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

LIBFT_DIR			=	libft/
LIBFT_NAME			=	libft.a
LIBFT				=	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

SERVER_SRCS_DIR		=	server_src/
SERVER_SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
SERVER_SRCS_LIST	=	server.c

CLIENT_SRCS_DIR		=	client_src/
CLIENT_SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
CLIENT_SRCS_LIST	=	client.c

OBJS_DIR			=	objs/

SERVER_OBJS_LIST	:=	$(patsubst %.c, %.o, $(SERVER_SRCS_LIST))
SERVER_OBJS			=	$(addprefix $(OBJS_DIR), $(SERVER_OBJS_LIST))

CLIENT_OBJS_LIST	:=	$(patsubst %.c, %.o, $(CLIENT_SRCS_LIST))
CLIENT_OBJS			=	$(addprefix $(OBJS_DIR), $(CLIENT_OBJS_LIST))

HEADERS				=	-I ./includes -I ./libft
LIBS				=	-L libft -lft

.PHONY : all clean fclean re

all : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(LIBFT) $(SERVER_OBJS)
	@echo -e "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	@echo -e "\033[32mBinary \033[1;32m$(SERVER_NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SERVER_SRCS_DIR)%.c includes/*.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo -e "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(CLIENT_NAME) : $(LIBFT) $(CLIENT_OBJS)
	@echo -e "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	@echo -e "\033[32mBinary \033[1;32m$(CLIENT_NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(CLIENT_SRCS_DIR)%.c includes/*.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo -e "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

$(LIBFT) :
	@make --no-print-directory -C $(LIBFT_DIR)

clean :
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo -e "\033[31mObjects files \033[1;31m$(SERVER_OBJS_LIST), $(CLIENT_OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean : clean
	@rm -rf $(LIBFT)
	@echo -e "\033[31mLib \033[1;31m$(notdir $(LIBFT))\033[1;0m\033[31m removed.\033[0m"
	@rm -rf $(SERVER_NAME)
	@echo -e "\033[31mBin \033[1;31m$(SERVER_NAME)\033[1;0m\033[31m removed.\033[0m"
	@rm -rf $(CLIENT_NAME)
	@echo -e "\033[31mBin \033[1;31m$(CLIENT_NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all
