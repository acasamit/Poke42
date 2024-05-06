NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -O0 -g
LIBMLX	:= ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include -I utils/get_next_line.h -I utils/ft_printf.h
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= so_long.c so_long2.c so_long3.c so_long4.c so_long5.c so_long6.c so_long7.c so_long8.c so_long9.c so_long10.c so_long11.c so_long12.c so_long13.c so_long14.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c so_long_utils5.c so_long_utils6.c dialog.c dialog2.c rocket_anim.c rocket_anim2.c fight_anim.c fight_anim2.c fight_anim3.c fight_anim4.c fight_anim5.c fight_anim6.c fight_anim7.c fight_anim8.c fight_anim9.c fight_anim10.c utils/get_next_line.c utils/get_next_line_utils.c utils/ft_printf.c utils/ft_printf_dependencies1.c utils/ft_printf_dependencies2.c
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)/build/libmlx42.a
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBMLX)/build/libmlx42.a:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBMLX)/build/libmlx42.a

re: fclean all

.PHONY: all clean fclean re

