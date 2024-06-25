# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 18:36:21 by lubrito-          #+#    #+#              #
#    Updated: 2024/06/25 13:30:03 by lubrito-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
HEAD = main.c
SRCS = pipex.c pipex_utils0.c pipex_utils1.c pipex_utils2.c
SRCS_BONUS = pipex_bonus.c
HEADER = pipex.h
LIBFTDIR = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -f 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
MAIN = $(HEAD:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(MAIN) $(LIBFTDIR) $(HEADER)
	@echo "Created objs"
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) $(LIBFTDIR) -I Libft -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS) $(SRCS) $(LIBFTDIR) $(HEAD)
	@echo "Created objs_bonus"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS) $(LIBFTDIR) -I Libft -o $(NAME_BONUS)

$(LIBFTDIR):
	$(MAKE) -C Libft

%.o: %.c
	$(CC) $(CFLAGS) -I Libft -c $< -o $@

debug:
	cc $(CFLAGS) -g -I Libft  *.c Libft/*.c

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(MAIN)
	$(MAKE) -C Libft clean

fclean: clean
	@echo "Deleted objs"
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C Libft fclean


re: fclean all

.PHONY: all clean fclean re bonus