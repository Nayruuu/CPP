# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/05/12 11:47:43 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CLANG = clang++

FLAGS = -Wall -Werror -Wextra -I includes/

SRC = main.cpp AException.cpp Overflow.cpp Underflow.cpp OperandFactory.cpp
SRC += EmptyStack.cpp NotEnoughNumbers.cpp DivideByZero.cpp NotEqual.cpp NotCharValue.cpp
SRC += NoExitCommand.cpp VMStack.cpp WrongModulo.cpp Token.cpp Lexer.cpp LexerException.cpp
OBJ = $(SRC:.cpp=.o)

SRC_PATH = srcs/
OBJ_PATH = objs/

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

.PHONY = all clean fclean re

$(NAME): $(OBJS)
	@$(CLANG) -o $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CLANG) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:	
		@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all
