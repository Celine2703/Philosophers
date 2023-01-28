SRCS	= 	philo.c\
			parsing.c\
			ft_atoi.c\
			ft_bzero.c\
			init.c\

DIR_SRC = srcs/

OBJ	= ${SRCS:.c=.o}

DIR_OBJ = srcs/objs/

OBJS= $(addprefix $(DIR_OBJ), $(OBJ))

DEP	= ${SRCS:.cpp=.d}

DEPS = $(addprefix $(DIR_OBJ), $(DEP))

NAME	= philo

CC	= cc

CFLAGS	= -MMD -Iincludes -Wall -Wextra -g -Werror -pthread

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)		

all:	${NAME}

clean:
		rm -f ${OBJS} ${DEPS}

fclean:	
		rm -f ${NAME}
		rm -f ${OBJS} $(DEPS)

re:		fclean
		make all

do : 	all
		./${NAME}


$(DIR_OBJ)%.o: $(DIR_SRC)%.c
				$(CC) $(CFLAGS) -c $< -o $@


.PHONY: all clean fclean re do

-include $(DEPS)