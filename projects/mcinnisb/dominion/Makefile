CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

test_help.o: dominion.o test_help.h test_help.c
	gcc -c test_help.c -g dominion.o

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o test_help.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o test_help.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o test_help.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o test_help.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o test_help.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o test_help.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o test_help.o
	gcc -o unittest1 -g unittest1.c dominion.o test_help.o rngs.o $(CFLAGS)

unittest2:dominion.o rngs.o test_help.o unittest2.c
	gcc -o unittest2 -g unittest2.c dominion.o test_help.o rngs.o $(CFLAGS)

unittest3: dominion.o rngs.o test_help.o unittest3.c
	gcc -o unittest3 -g unittest3.c dominion.o test_help.o rngs.o $(CFLAGS)

unittest4: dominion.o rngs.o test_help.o unittest4.c
	gcc -o unittest4 -g unittest4.c dominion.o test_help.o rngs.o $(CFLAGS)

cardtest1: dominion.o rngs.o test_help.o cardtest1.c
	gcc -o cardtest1 -g cardtest1.c dominion.o test_help.o rngs.o $(CFLAGS)

cardtest2: dominion.o rngs.o test_help.o cardtest2.c
	gcc -o cardtest2 -g cardtest2.c dominion.o test_help.o rngs.o $(CFLAGS)

cardtest3: dominion.o rngs.o test_help.o cardtest3.c
	gcc -o cardtest3 -g cardtest3.c dominion.o test_help.o rngs.o $(CFLAGS)

cardtest4: dominion.o rngs.o test_help.o cardtest4.c
	gcc -o cardtest4 -g cardtest4.c dominion.o test_help.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestcard1.out: randomtestcard1
	./randomtestcard1 $(ARG) &> randomtestcard1.out
	gcov dominion.c -b -f >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2
	./randomtestcard2 $(ARG) &> randomtestcard2.out
	gcov dominion.c -b -f >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer $(ARG)  &> randomtestadventurer.out
	gcov dominion.c -b -f >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 &> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./unittest2 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./unittest3 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./unittest4 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardtest1 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardtest2 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardtest3 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./cardtest4 &>> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
