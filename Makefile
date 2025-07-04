# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 20:53:25 by itakumi           #+#    #+#              #
#    Updated: 2025/07/04 09:23:11 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Sources
SRC_DIR = src
SRCS = main.c\
		utils/base_operation.c\
		utils/base_operation2.c\
		utils/binary_search.c\
		utils/check_error.c\
		utils/coordinate_compression.c\
		utils/exit_and_errormsg.c\
		utils/lis.c\
		utils/calculate_cost.c\
		utils/math.c\
		utils/get.c\
		utils/merge_insert_sort.c\
		utils/quick_sort.c\
		utils/sort_over_six.c\
		utils/sort_under_five.c\
		utils/ut_atoi_numbers.c\
		utils/ut_atoi_with_error.c\
		utils/ut_issign.c\
		utils/ut_isspace.c\
		utils/ut_produce_double_p.c\
		circular_bidirect_list/produce_list.c\
		circular_bidirect_list/cdll_add_back.c\
		circular_bidirect_list/cdll_add_front.c\
		circular_bidirect_list/cdll_clear.c\
		circular_bidirect_list/cdll_delone.c\
		circular_bidirect_list/cdll_iter.c\
		circular_bidirect_list/cdll_last.c\
		circular_bidirect_list/cdll_new.c\
		circular_bidirect_list/cdll_size.c\
		singly_list/lst_add_back.c\
		singly_list/lst_all.c\
		singly_list/lst_last.c\
		singly_list/lst_new.c\
		singly_list/lst_clear.c

#Objets
OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#Includes
HEAD_DIR = include
HEADERS = -I $(HEAD_DIR)
# $(foreach l, $(filter-out ./, $(sort $(dir $(SRCS)))), -I $(HEAD_DIR)/$(l))

#Library
LIB_DIR = lib
LIB = libft

LIBS_HEAD = $(foreach l, $(LIB), -I $(LIB_DIR)/$(l))
LIBS = $(foreach l, $(LIB), $(LIB_DIR)/$(l)/$(l).a)

#color
COLOR = \e[
COLOR2 = m
COLOR_END = \e[0m
FONT_GREEN = 32
FONT_YELLOW = 33
FONT_MAKE = $(COLOR)$(FONT_GREEN)$(COLOR2)
FONT_DELETE = $(COLOR)$(FONT_RED)$(COLOR2)
FONT_WARN = $(COLOR)$(FONT_YELLOW)$(COLOR2)

#Rules
$(NAME): $(LIBS) $(OBJS)
	@echo -n "$(FONT_MAKE)"
	$(CC) $(CFLAGS) -g $(HEADERS) $(LIBS_HEAD) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(COLOR_END)"

all: $(NAME)

clean:
ifeq ("$(wildcard $(OBJ_DIR))", "$(OBJ_DIR)")
	@echo -n "$(FONT_WARN)"
	rm -rf $(OBJ_DIR)
	$(LIB_CLEAN)
	@echo "$(COLOR_END)"
endif

fclean: clean
	@echo -n "$(FONT_DELETE)"
	rm -f $(NAME)
	$(LIB_FCLEAN)
	rm -rf $(OBJ_DIR)
	@echo "$(COLOR_END)"

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -n "$(FONT_MAKE)"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g $(HEADERS) $(LIBS_HEAD) -c $< -o $@
	@echo "$(COLOR_END)"

define LIB_BUILD
	@echo -n "$(FONT_MAKE)"
	$(MAKE) all -C $(dir $*)
	@echo "$(COLOR_END)"
endef

%.a:
	$(LIB_BUILD)

define LIB_CLEAN
	@echo -n "$(FONT_MAKE)"
	$(MAKE) clean -C "$(LIB_DIR)/$(LIB)"
	@echo "$(COLOR_END)"
endef

define LIB_FCLEAN
	@echo -n "$(FONT_DELETE)"
	$(MAKE) fclean -C $(LIB_DIR)/$(LIB)
	@echo "$(COLOR_END)"
endef

debug: CFLAGS=
debug: re

.PHONY: all clean fclean re debug
