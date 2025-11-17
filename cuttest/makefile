# Makefile
LUADIR = ..

myluaapp: main.c
	gcc main.c $(LUADIR)/liblua.a -I$(LUADIR) -o testapp -lm -ldl -pthread

clean:
	rm -f myluaapp