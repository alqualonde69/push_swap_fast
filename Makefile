# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 13:25:42 by shunt             #+#    #+#              #
#    Updated: 2019/08/10 13:25:49 by shunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF				=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m
REV				=	\033[7m
BLACK			=	\033[30m
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
PINK			=	\033[35m
CYAN			=	\033[36m
GREY			=	\033[37m
BLACK_B			=	\033[40m
RED_B			=	\033[41m
GREEN_B			=	\033[42m
YELLOW_B		=	\033[43m
BLUE_B			=	\033[44m
PINK_B			=	\033[45m
CYAN_B			=	\033[46m
GREY_B			=	\033[47m

C_NAME			=	checker
P_NAME			=	push_swap

LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/includes/

LIB_NAME		=	libft.a

LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix -I, $(LIB_INC_PATH))

SRC_PATH		=	srcs/
INC_PATH		=	includes/

C_SRC_NAME		=	applyrule.c atoi_stack.c b_stack.c c_main.c ch_fd.c\
                    ch_flags.c chckstack.c cycle.c error.c frav.c freetps.c\
                    free_t_ps.c hd.c isdup.c is_nu.c is_rule.c issort.c print.c\
                    push.c rotate.c swap.c

P_SRC_NAME		=	add_t_rl.c app_opt1.c app_opt2.c app_opt3.c app_opt4.c\
                    applyrule.c atoi_stack.c atst.c b_stack.c chckstack.c\
                    error.c frav.c freetps.c free_t_ps.c hd.c isdup.c\
                    is_mn_ra.c is_nu.c issort.c issort2.c last_a.c m_a.c opt1.c\
                    opt2.c opt3.c opt4.c ps_main.c push.c push_swap.c\
                    print_list.c ps_cut.c rotate.c sequence.c swap.c

C_SRC			=	$(addprefix $(SRC_PATH), $(C_SRC_NAME))
P_SRC			=	$(addprefix $(SRC_PATH), $(P_SRC_NAME))
INC				=	$(addprefix -I, $(INC_PATH))

all:				$(C_NAME) $(P_NAME)

$(C_NAME):			$(LIB)
	@gcc -Wall -Wextra -Werror $(INC) $(LIB_INC) -o $(C_NAME) $(C_SRC) -L libft -lft
	@echo "  🌸 🌸 🌸     🌸 🌸 🌸"
	@echo "🌸       🌸 🌸       🌸"
	@echo "🌸        🌸        🌸"
	@echo " 🌸  $(PINK)CHECKER READY🌸"
	@echo "   🌸           🌸"
	@echo "     🌸       🌸"
	@echo "       🌸   🌸"
	@echo "         🌸"
	@echo ""

$(P_NAME):			$(LIB)
	@gcc -Wall -Wextra -Werror $(INC) $(LIB_INC) -o $(P_NAME) $(P_SRC) -L libft -lft
	@echo "💚 💚 💚 💚 💚 💚 💚 💚 💚 💚 💚 💚"
	@echo "💚                     💚"
	@echo "💚    $(GREEN)PUSH_SWAP READY  💚"
	@echo "💚                     💚"
	@echo "💚 💚 💚 💚 💚 💚 💚 💚 💚 💚 💚 💚"
	@echo ""

$(LIB):
	@make -C libft

clean:
	@make -C libft clean

fclean:				clean
	@rm -rf $(C_NAME)
	@rm -rf $(P_NAME)
	@make -C libft fclean
	@echo "$(BOLD)$(GREEN)BINARIES DELETED ✅"

re: fclean all
