CC = gcc
CFLAGS = -Iinclude
DEPS = include/matriz.h
OBJ = src/main.o src/matriz.o
LDFLAGS = -lm

# para compilar archivos .c a .o
%.o: src/%.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

#para enlazar los archivos .o en un ejecutable
proyecto-matrices: $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)

#Limpiar archivos intermedios (.o)
clean:
    rm -f src/*.o proyecto-matrices.exe