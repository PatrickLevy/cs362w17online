CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o	

	
	
randomtestcard1.out: randomtestcard1.c  dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o

	./randomtestcard1 >> randomtestcard1.out

	gcov -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out	
	
	
randomtestcard2.out: randomtestcard2.c  dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o

	./randomtestcard2 >> randomtestcard2.out

	gcov -b dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out		
	
	
randomtestadventurer.out: randomtestadventurer.c  dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o

	./randomtestadventurer >> randomtestadventurer.out

	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out		
	
	
	

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestcard1.out randomtestcard2.out randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe randomtestcard1 randomtestcard2 randomtestadventurer testInit testInit.exe *.gcov *.gcda *.gcno *.so