CC=gcc
CFLAGS=-O3 -std=gnu99 -ftree-vectorize -ftree-vectorizer-verbose=5
SETSIZE=1000

all: naive opt dataset

setgen:
	$(CC) $(CFLAGS) make_sample.c -o setgen

dataset: setgen
	./setgen $(SETSIZE) > dataset

naive:
	$(CC) $(CFLAGS) nucleotides_naive.c -o $(@)

opt:
	$(CC) $(CFLAGS) nucleotides_opt.c -o $(@)

clean:
	-rm -fr *.o
	-rm -fr setgen
	-rm -fr naive
	-rm -fr opt

distclean: clean
	-rm -fr dataset

.PHONY: dataset clean distclean all
