CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -framework OpenGL -framework AppKit

SRCS = mandatory/main.c mandatory/fract-ol_init.c mandatory/needed.c \
       mandatory/render.c mandatory/events.c mandatory/math_wdakxi.c
BONUS_SRCS = bonus/main_bonus.c bonus/fract-ol_init_bonus.c bonus/needed_bonus.c \
             bonus/render_bonus.c bonus/events_bonus.c bonus/math_wdakxi_bonus.c

TARGET = fractol
BONUS_TARGET = fractol_bonus

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

bonus: $(BONUS_TARGET)

$(BONUS_TARGET): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_TARGET) $(BONUS_OBJS) $(LIBS)

%.o: %.c mandatory/fractol.h bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: clean
	rm -f $(TARGET) $(BONUS_TARGET)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
