name = board
flags = -Wall -Wextra -Werror

files = chess/board.c chess/board_init.c

header_files = chess/board.h chess/square.h

o_file = $(files:.c=.o)

all: $(name)

$(name): $(o_file)
	@cc $(flags) $(o_file) -o $(name)

%.o: %.c $(header_files)
	@cc $(flage) -c $< -o $@

clean:
	@rm -rf $(o_file) $(name);

re: clean all

