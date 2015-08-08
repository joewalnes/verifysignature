# 2015, Joe Walnes, Sneaky Squid

run: example
	./example
.PHONY: run

example: example.o verifysignature.o
example.o verifysignature.o: verifysignature.h

clean:
	rm -f example *.o
.PHONY: clean
