.PHONY: all clean fclean re

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -Ilibftprintf/include

LIBFTPRINTF_DIR	:=	libftprintf
LIBFTPRINTF		:=	$(LIBFTPRINTF_DIR)/libftprintf.a

SERVER_SRCS		:=	server.c
CLIENT_SRCS		:=	client.c

SERVER_OBJS		:=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS		:=	$(CLIENT_SRCS:.c=.o)

SERVER			:= server
CLIENT			:= client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFTPRINTF) $(SERVER) $(CLIENT)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

$(SERVER): $(SERVER_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@ $(LIBFTPRINTF)

$(CLIENT): $(CLIENT_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $@ $(LIBFTPRINTF)

clean: 
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFTPRINTF_DIR) fclean

re: fclean all
