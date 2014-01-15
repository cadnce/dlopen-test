CC=g++
CFLAGS= -ggdb
SHARED_LIBS= libhello.so

%.so: %.c
	$(CC) -shared -fPIC $< -o $@ $(CFLAGS)

loader: loader.c $(SHARED_LIBS)
	$(CC) -o $@ $< -ldl $(CFLAGS)

.PHONY:clean
clean:
	rm -f *.o *.so; \
	rm -f loader
