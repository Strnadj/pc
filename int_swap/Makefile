CC=gcc
BINARY=swap
FILES=swap.c

# Implicit target
build:
	@echo Compiling ...
	${CC} -Wall ${FILES} -o ${BINARY}

build_prod:
	@echo Compiling with optimization ...
	@$(CC) -o2 $(FILES) -o ${BIN}

clean:
	@echo Cleaning ..
	rm ${BINARY}
