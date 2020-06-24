CC = gcc
FILES = src/write.c src/read.c src/main.c
OUT = run

all: $(FILES)
	$(CC) $(FILES) -o $(OUT)
	
runall: $(FILES)
	$(CC) $(FILES) -o $(OUT)
	./$(OUT)

clean:
	rm -f *.o
	rm -f $(OUT)
	rm -f src/$(OUT)
	rm -f src/*.o
