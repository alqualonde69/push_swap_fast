# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 13:43:16 by shunt             #+#    #+#              #
#    Updated: 2019/04/15 16:14:48 by shunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD		=	\033[1m
UNDERLINE	=	\033[4m
REV			=	\033[7m
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
GREY		=	\033[37m
BLACK_B		=	\033[40m
RED_B		=	\033[41m
GREEN_B		=	\033[42m
YELLOW_B	=	\033[43m
BLUE_B		=	\033[44m
PINK_B		=	\033[45m
CYAN_B		=	\033[46m
GREY_B		=	\033[47m

NAME		=	libft.a

SRC_PATH	=	./srcs/
OBJ_PATH	=	./objs/
INC_PATH	=	./includes/

SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			=	$(addprefix -I, $(INC_PATH))

SRC_NAME	=	ft_atoi.c ft_bin.c ft_bzero.c ft_calc.c ft_df.c ft_isalnum.c\
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnum.c ft_isprint.c\
				ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
				ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
				ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
				ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
				ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
				ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
				ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
				ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
				ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
				ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c\
				ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_itoa_fp.c\
				mexp.c str_ad.c e_zrs.c ft_ox.c pw.c str_ml.c fld_edge.c ft_p.c\
				pw_to_str.c t_str.c fr_p.c ft_printf.c reader.c wzrs.c ft_c.c\
				res_o_fr.c zrs.c ft_e.c ft_round.c rnd.c add_z.c int_p.c\
				rnd_z.c apply_flags.c ft_fld.c rndg.c ft_g.c rndg_z.c c_str.c\
				mantis.c ft_itoa_base.c s_str.c ft_rg.c res_w_fr.c\
				ft_put_percent.c chck_xu.c chck_x.c chck_sr.c chck_p.c chck_o.c\
				chck_g.c chck_f.c chck_e.c	chck_di.c chck_c.c chck_b.c\
				chck_u.c ft_u.c ft_s.c ft_free_output.c ft_bufjoin.c\
				ft_put_out.c ft_solver.c ft_app_d_prs.c ft_add_pl.c ft_solver.c\
				ft_app_width.c ft_app_fl.c ft_cycle6.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

all:			$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo -n ⭐ ️

$(NAME): $(OBJ)
	@echo "\n\n🌕 🌖 🌗 🌘 🌚 🌒 🌓 🌔 🌕"
	@echo "🌜 $(BOLD)$(YELLOW)LIBFT IS READY🌛"
	@echo "🌕 🌖 🌗 🌘 🌚 🌒 🌓 🌔 🌕\n"
	@ar -rc $(NAME) $?

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(BOLD)$(GREEN)OBJECTS DELETED  ✅"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BOLD)$(GREEN)LIBFT DELETED    ✅"

re: fclean all

