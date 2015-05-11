# 2015, Joe Walnes, Sneaky Squid

run: example
	./example
.PHONY: run

example: example.c verifysignature.c

clean:
	rm -f example
.PHONY: clean
