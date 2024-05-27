INCLUDEDIR := /usr/include
LIBDIR := /usr/lib
all: libllist.so

libllist.so: llist.c
	gcc -shared -o libllist.so llist.c

install: libllist.so
	install -D -m 644 llist.h $(INCLUDEDIR)/llist.h
	install -D -m 755 libllist.so $(LIBDIR)/libllist.so

uninstall:
	rm -f $(INCLUDEDIR)/llist.h
	rm -f $(LIBDIR)/libllist.so

clean:
	rm -f libllist.so