# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvorstma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:03:01 by jvorstma          #+#    #+#              #
#    Updated: 2023/12/04 14:00:38 by jvorstma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

NAME= cub3D
HEADER= cub_3_d.h
LIBFT_DIR= ./libft
LIBFT= ./libft/libftprintf.a

ODIR= obj

SOURCE= main.c \

OBJECTS= $(addprefix $(ODIR)/,$(SOURCE:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(ODIR):
	@mkdir -p $(ODIR)

$(ODIR)/%.o: %.c $(HEADER) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(ODIR)" ]; then \
		$(RM) $(ODIR); \
	fi
	@$(MAKE) clean -sC $(LIBFT_DIR)

fclean: clean
	@if [ -x "$(NAME)" ]; then \
		$(RM) $(NAME); \
	fi
	@$(MAKE) fclean -sC $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
