CFLAGS = -fprofile-arcs -fpic -coverage -lm

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

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittests: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o 
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS) 
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtests: cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o 
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS) 
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtests: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.o rngs.o
	gcc -o randomtest1 -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS) 
	gcc -o randomtest2 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtest3 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtest1.out:
	gcc -o randomtest1 -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS) 
	./randomtest1 &> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out	

randomtest2.out:
	gcc -o randomtest2 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randomtest2 &> randomtestcard1.out
	gcov -b -c dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out	

randomtest3.out:
	gcc -o randomtest3 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtest3 &> randomtestcard2.out
	gcov -b -c dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out	

randomtestresults.out: 
	make randomtest1.out
	make randomtest2.out
	make randomtest3.out


unittestresults.out: unittests cardtests
	make unittests
	make cardtests 
	./unittest1 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
		
unit2out:
	./unittest2 &> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unit3out:
	./unittest3 &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unit4out:
	./unittest4 &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player     

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittests cardtests unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtest1 *.out *.gcov *.gcda *.gcno *.so
