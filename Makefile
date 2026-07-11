name = board
flags = -Wall -Wextra -Werror

files = board.c 

o_file = $(files:.c=.o)

all: $(name)

$(name): $(o_file)
	@cc $(flags) $(o_file) -o $(name)

%.o: %.c board.h
	@cc $(flage) -c $< -o $@

clean:
	@rm -rf $(o_file) $(name);

re: clean all

