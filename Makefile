# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:13:52 by rpinchas          #+#    #+#              #
#    Updated: 2023/03/12 19:13:35 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME :=	push_swap
HEAD := push_swap.h
CFLAGS := -Werror -Wall -Wextra
DEBUG := -g

#FILES
SRCDIR := src
SRC_F := push_swap_main.c\
	push_swap_check.c\
	push_swap_utils.c\
	push_swap_sort.c\
	push_swap_sort_utils.c\
	push_swap_radix.c\
	push_swap_free.c
SRC := 	${addprefix ${SRCDIR}/, ${SRC_F}}
OBJDIR := obj
OBJ_F :=  ${SRC_F:%.c=%.o}
OBJ :=	${addprefix ${OBJDIR}/, ${OBJ_F}}

#LIBFT
LIBFTDIR := libft
LIBFT_F := libft.a
LIBFT := ${addprefix ${LIBFTDIR}/, ${LIBFT_F}}

#COLORS
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m

TESTDIR = tester
FILE_F = testfile
TESTER_F = tester.sh
TESTER = ${addprefix ${TESTDIR}/, ${TESTER_F}}
FILE = ${addprefix ${TESTDIR}/, ${FILE_F}}

#RULES
all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@echo "${YELLOW}Compiling...${RESET}"
	${CC} ${CFLAGS} -o $@ ${OBJ} $< 
	@echo "${GREEN}Run Code${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c obj_check
	${CC} ${CFLAG} ${DEBUG} -c $< -o $@

obj_check: 
	@echo "${BLUE}Making object files...${RESET}"
	@mkdir -p ${OBJDIR}

${LIBFT}: ${LIBFTDIR}
	@make -C $^ -s

clean:
	@echo "${GREEN}Removing object files...${RESET}"
	@rm -f ${OBJ}
	@rm -rf ${OBJDIR}
	@make -C ${LIBFTDIR} clean -s
	@echo "${BLUE}DONE!${RESET}"

fclean: clean tclean
	@echo "${GREEN}Removing executables...${RESET}"
	@rm	-rf ${NAME}
	@make -C ${LIBFTDIR} fclean -s
	@echo "${BLUE}DONE!${RESET}"

re: fclean all

${FILE}:
	test -e ${FILE} || touch ${FILE}

test: all ${FILE}
	@echo "${YELLOW}+++RUNNING TESTS+++${RESET}"
	@echo "${BLUE}\nTEST 1: SINGLE VS. MULTIPLE ARGS\n${RESET}"
	./${TESTER} -1000 1000 100 0 0
	./${TESTER} -1000 1000 100 0 1
	./${TESTER} -1000 1000 100 0 2
	@echo "${BLUE}\nTEST 2: NOT ALLOWED CHAR\n${RESET}"
	./${TESTER}	-1000 1000 100 1 0
	./${TESTER} -1000 1000 100 1 1
	./${TESTER}	-1000 1000 100 1 2
	@echo "${BLUE}\nTEST 3: MAX INT\n${RESET}"
	./${TESTER}	-1000 1000 100 2 0
	./${TESTER}	-1000 1000 100 2 1
	./${TESTER}	-1000 1000 100 2 2
	@echo "${BLUE}\nTEST 4: DUPLICATE\n${RESET}"
	./${TESTER}	-1000 1000 100 3 0
	./${TESTER}	-1000 1000 100 3 1
	./${TESTER}	-1000 1000 100 3 2

tclean:
	@echo "${GREEN}Removing testfiles...${RESET}"
	@rm -f ${FILE}
	@echo "${BLUE}DONE!${RESET}"

.PHONY: all clean fclean re
