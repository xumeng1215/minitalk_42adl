# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 16:22:08 by mexu / Char       #+#    #+#              #
#    Updated: 2024/06/07 15:42:24 by mexu / Char      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = client.c server.c
CFLAGS = -Wall -Wextra -Werror
# OBJ = $(SRC:.c=.o)
NAME = minitalk

FT_PRINTF = ./ft_printf/ft_printf.a
LIBFT = ./libft/libft.a

FT_PRINTF_MAKE = make --no-print-directory -C ft_printf/
LIBFT_MAKE = make --no-print-directory -C libft/

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT)
		@cc $(CFLAGS) -o client client.c $(FT_PRINTF) $(LIBFT)
		@cc $(CFLAGS) -o server server.c $(FT_PRINTF) $(LIBFT)

$(FT_PRINTF):
		@$(FT_PRINTF_MAKE)
$(LIBFT):
		@$(LIBFT_MAKE)

bonus:	$(FT_PRINTF) $(LIBFT)
		@cc $(CFLAGS) -o client_bonus client_bonus.c $(FT_PRINTF) $(LIBFT)
		@cc $(CFLAGS) -o server_bonus server_bonus.c $(FT_PRINTF) $(LIBFT)

clean:
		@$(FT_PRINTF_MAKE) clean
		@$(LIBFT_MAKE) clean

fclean:	clean
		@rm -rf server
		@rm -rf client
		@rm -rf server_bonus
		@rm -rf client_bonus		
		@$(FT_PRINTF_MAKE) fclean
		@$(LIBFT_MAKE) fclean

re: fclean all




.phony: re clean all fclean bonus
