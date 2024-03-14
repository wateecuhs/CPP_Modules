NAME				=	accounting

CC					=	g++
SRCS				=	tests.cpp Account.cpp
OBJS				=	$(SRCS)
DEPS_FLAGS			=	-MMD -MP
BASE_CFLAGS			=	-g3 -Wall -Wextra -Werror
BASE_DEBUG_CFLAGS	=	-g3
DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=address
FLAGS				=	$(BASE_CFLAGS)
RM					=	rm -rf

.PHONY:		all
all:
			$(MAKE) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

.PHONY:	clean
clean:
			$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
			$(RM) $(NAME)

.PHONY:	debug
debug:	fclean
			$(MAKE) -j FLAGS="$(DEBUG_CLFAGS)"

.PHONY:	re
re:		fclean
			$(MAKE) all

-include $(DEPS)
%.o : %.c
			$(CC) $(FLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
