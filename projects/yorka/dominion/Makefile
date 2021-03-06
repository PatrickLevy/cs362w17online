# Antonina (Toni) York
# OSU CS 362 Winter 2017
# Dominion Makefile

CFLAGS = -Wall -fpic -coverage -lm
SEED = 1000

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
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)	
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "" > randomtestadventurer.out
	echo "Results of Random Test of Adventurer" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	echo "Change PRINT_TESTS to 1 to see prinouts." >> randomtestadventurer.out
	
	echo "" >> randomtestadventurer.out
	echo "=============================================" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	randomtestadventurer $(SEED) >> randomtestadventurer.out
	
	echo "" >> randomtestadventurer.out
	echo "=============================================" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	
	echo "gcov results:" >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	#cat dominion.c.gcov >> randomtestadventurer.out
	
	echo "=============================================" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	
	echo "Done!" >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	
randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	echo "" > randomtestcard1.out
	echo "Results of Random Test of Smithy" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	echo "Change PRINT_TESTS to 1 to see prinouts." >> randomtestcard1.out
	
	echo "" >> randomtestcard1.out
	echo "=============================================" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard1 $(SEED) >> randomtestcard1.out
	
	echo "" >> randomtestcard1.out
	echo "=============================================" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	
	echo "gcov results:" >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	#cat dominion.c.gcov >> randomtestcard1.out
	
	echo "=============================================" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	
	echo "Done!" >> randomtestcard1.out
	echo "" >> randomtestcard1.out
	
randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	echo "" > randomtestcard2.out
	echo "Results of Random Test of Village" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	echo "Change PRINT_TESTS to 1 to see prinouts." >> randomtestcard2.out
	
	echo "" >> randomtestcard2.out
	echo "=============================================" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard2 $(SEED) >> randomtestcard2.out
	
	echo "" >> randomtestcard2.out
	echo "=============================================" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	
	echo "gcov results:" >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	#cat dominion.c.gcov >> randomtestcard2.out
	
	echo "=============================================" >> randomtestcard2.out
	echo "" >> randomtestcard2.out
	
	echo "Done!" >> randomtestcard2.out
	echo "" >> randomtestcard2.out

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	echo "" > unittestresults.out
	echo "Results of Dominion Unit Tests" >> unittestresults.out
	echo "" >> unittestresults.out
	echo "Change PRINT_TESTS to 1 in individual test files to see prinouts." >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "gcov results:" >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	
	echo "=============================================" >> unittestresults.out
	echo "" >> unittestresults.out
	
	echo "Dominion unit tests complete!" >> unittestresults.out
	echo "" >> unittestresults.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o *.out randomtestadventurer randomtestcard1 randomtestcard2 testDrawCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
