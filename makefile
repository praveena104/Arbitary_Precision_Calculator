OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
slist.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o

