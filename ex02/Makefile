SRCS	= PmergeMe.cpp main.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= PmergeMe
CLANG	= c++ 
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -std=c++98

${NAME}:	${OBJS}
				${CLANG} ${CFLAGS} -o ${NAME} ${OBJS}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all

.PHONY:		all clean fclean re