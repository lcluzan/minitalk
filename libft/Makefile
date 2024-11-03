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

NAME					=	libft.a
SHELL					=	/bin/bash

CC						=	cc
CFLAGS					=	-Wall -Wextra -Werror

SRCS_DIR				=	./

LIBC_SRCS_LIST			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
							ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
							ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
							ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
							ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strsplit.c \
							ft_strsub.c

ADDITIONAL_SRCS_LIST	=	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
							ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

GNL_SRCS_LIST			=	get_next_line_utils.c get_next_line.c

BONUS_SRCS_LIST 		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
							ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
							ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCS_LIST				=	${LIBC_SRCS_LIST} ${ADDITIONAL_SRCS_LIST} ${GNL_SRCS_LIST} ${BONUS_SRCS_LIST}
SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR				=	objs/
OBJS_LIST				=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADERS					=	-I ./includes

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	@echo -e "\033[37mLinking...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo -e "\033[32mLibrary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo -e "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo -e "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo -e "\033[31mLib \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all
