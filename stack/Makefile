# Set default variables
CC=gcc # cl.exe
INPUT_FILES=main.c stack.c
BIN=program

build: print_information
	@echo Compiling ...
	${CC} -Wall ${INPUT_FILES} -o ${BIN}

print_information:
	@echo This program creating stack cool code.

build_prod:
	@echo Compiling optimization binary ...
	@$(CC) -o 2 $(INPUT_FILES) -o $(BIN)

clean:
	rm ${BIN}
