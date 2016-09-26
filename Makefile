# 2015, Joe Walnes, Sneaky Squid

run: example example-cpp
	./example
	./example-cpp
.PHONY: run

example.o verifysignature.o: verifysignature.h
example: example.o verifysignature.o

example-cpp.o: verifysignature.h
example-cpp: example-cpp.o verifysignature.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f example example-cpp *.o
.PHONY: clean
