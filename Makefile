CC = g++
RM = rm -fv
PACK = pack
UNPACK = unpack

CFLAGS = -Wextra -Wall -ggdb -O0 -std=c++14
LDLIBS =

default: bin/$(PACK) bin/$(UNPACK)

bin/$(PACK): bin/$(PACK).o bin/error.o bin/data.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

bin/error.o: src/error.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

bin/data.o: src/data.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

bin/$(UNPACK): bin/$(UNPACK).o bin/error.o  bin/data.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

bin/$(PACK).o: src/$(PACK).cpp
	$(CC) $(CFLAGS) -o $@ -c $<

bin/$(UNPACK).o: src/$(UNPACK).cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean
clean:
	$(RM) bin/*.o bin/$(PACK) bin/$(UNPACK)
