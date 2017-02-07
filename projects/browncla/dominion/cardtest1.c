/*cardtest1.c*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

/* Pre-Conditions: state->phase == 0, the player must be in the action phase
                         state->numActions > 0, the player must have an action to play
                         The name of the card must be adventurer and the value must be between 7 and 26
         Post-Conditions: state->handCount[currentPlayer] should have increased by the number of drawn treasures up to 2 treasure cards
                          state->numActions must be >= 0 because the number of actions is not changed in this function
                          The adventurer card should be in the discard pile
      
int playAdventurer(struct gameState *state, int currentPlayer, int handPos, int card){

       int z=0;
       int drawntreasure = 0;
       int temphand[MAX_HAND];
       int startNumCards = state->handCount[currentPlayer]; // storing the starting number of cards for test
       
      // drawn treasure is the number of cards that have been drawn that are treasure cards
      // keep going until 2 treasure cards are drawn
      while(drawntreasure<1){ //BUG
        //if the deck is empty we need to shuffle discard and add to deck
        if (state->deckCount[currentPlayer] <1){
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
          drawntreasure++;
        else{
          temphand[z]=cardDrawn; //storing the non-treasure drawn card in a temporary hand to discard before continuing play
          state->handCount[currentPlayer]--; //removing the non-treasure card from the current hand
        
          z++;
          }
      }
      //discarding the non-treasure cards that were drawn. 
      while(z-1>0){ //BUG
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn 
        z=z-1;
      }

      discardCard(handPos, currentPlayer, state, 0); // discard the adventure card since it has been played

}*/

//Own assert function
int asserttrue(int input, int number){
	if (input){
		printf("\tTEST %d SUCCESSFUL\n", number);
	}
	else
		printf("\tTEST %d FAILED\n", number);
	return 0;
}

int main(){

	int i, result, success, tester;
    int seed = 1000;
    int numPlayers = 2;
    int currentPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, salvager, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// placing the card in the players hand
	G.hand[currentPlayer][2] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// ----------- TEST 1: Test correct return statements for valid input -----------
	printf("%s TEST 1: Correct return statements for valid input\n", TESTCARD);
	result = playAdventurer(&testG, currentPlayer, 2);
	if (result == 0){
		asserttrue(1, 1);
	}
	else{
		asserttrue(0, 1);
	}
	// ----------- TEST 2: Test phase before and after is 0 -----------
	printf("%s TEST 2: Phase stays as phase 0\n", TESTCARD);
	if (result == 0){
		if (testG.phase == G.phase){
			asserttrue(1, 2);
		}
		else{
			asserttrue(0, 2);
		}
	}
	else{
		printf("TEST 2 could not be run due to invalid input\n");
	}
	// ----------- TEST 3: Test number of actions before is > 1 -----------
	printf("%s TEST 3: Number of actions after is decreased by 1\n", TESTCARD);
	if (result == 0){
		if (testG.numActions == (G.numActions - 1)){
			asserttrue(1, 3);
		}
		else{
			asserttrue(0, 3);
		}
	}
	else{
		printf("TEST 3 could not be run due to invalid input\n");
	}
	// ----------- TEST 4: Test number of actions after is greater than 0 -----------
	printf("%s TEST 4: Number of actions after is greater than 0\n", TESTCARD);
	if (result == 0){
		if (testG.numActions > 0){
			asserttrue(1, 4);
		}
		else{
			asserttrue(0, 4);
		}
	}
	else{
		printf("TEST 4 could not be run due to invalid input\n");
	}
	// ----------- TEST 5: Test handCount of player increased by 1 (+2 treasures - adventurer) -----------
	printf("%s TEST 5: handCount for current player has increased by 1\n", TESTCARD);
	if (result == 0){
		if (testG.handCount[currentPlayer] == G.handCount[currentPlayer] + 1){
			asserttrue(1, 5);
		}
		else{
			asserttrue(0, 5);
		}
	}
	else{
		printf("TEST 5 could not be run due to invalid input\n");
	}
	// ----------- TEST 6: Test that the Adventurer card is in the discard pile -----------
	printf("%s TEST 6: Adventurer card is in the discard pile\n", TESTCARD);
	if (result == 0){
		if (testG.discard[currentPlayer][testG.discardCount[currentPlayer]] == adventurer){
			asserttrue(1, 6);
		}
		else{
			asserttrue(0, 6);
		}
	}
	else{
		printf("TEST 6 could not be run due to invalid input\n");
	}
	// ----------- TEST 7: Test that the players total number of cards has not changed -----------
	printf("%s TEST 7: Other players have not gained cards\n", TESTCARD);
	if (result == 0){
		if (testG.handCount[otherPlayer] + testG.deckCount[otherPlayer] + testG.discardCount[otherPlayer] !=
			G.handCount[otherPlayer] + G.deckCount[otherPlayer] + G.discardCount[otherPlayer]){
			asserttrue(0, 7);
		}
		else{
			asserttrue(1, 7);
		}
	}
	else{
		printf("TEST 7 could not be run due to invalid input\n");
	}
	// ----------- TEST 8: Test that the number of victory (province, estate, duchy) cards has not changed -----------
	printf("%s TEST 8: Victory cards have not been affected\n", TESTCARD);
	if (result == 0){
		for (i = estate; i <= province; i++){
			if (testG.supplyCount[i] != G.supplyCount[i]){
				asserttrue(0, 8);
				success = 0;
				break;
			}
			else{
				success = 1;
			}
		}
		if (success == 1){
			asserttrue(1, 8);
		}
	}
	else{
		printf("TEST 8 could not be run due to invalid input\n");
	}
	// ----------- TEST 9: Test that number of kingdom cards (supply...) has not changed -----------
	printf("%s TEST 9: Supply cards have not been changed\n", TESTCARD);
	if (result == 0){
		for (i = copper; i <= treasure_map; i++){
			if (testG.supplyCount[i] != G.supplyCount[i]){
				asserttrue(0, 9);
				success = 0;
				break;
			}
			else{
				success = 1;
			}
		}
		if (success == 1){
			asserttrue(1, 9);
		}
	}
	else{
		printf("TEST 9 could not be run due to invalid input\n");
	}

	// ----------- TEST 10 : Test amount of coins has increased -----------
	printf("%s TEST 10: Amount of coins has increased\n", TESTCARD);
	if (result == 0){
		tester = 0;
		for (i = 0; i < testG.handCount[currentPlayer]; i++){
			if (testG.hand[currentPlayer][i] == copper)
				tester += 1;
			else if (testG.hand[currentPlayer][i] == silver){
				tester += 2;
			}
			else if (testG.hand[currentPlayer][i] == gold){
				tester += 3;
			}
		}
		if (tester > testG.coins){
			asserttrue(1, 10);
		}
		else{
			asserttrue(0, 10);
		}
	}
	else{
		printf("TEST 10 could not be run due to invalid input\n");
	}

	// reset a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// placing the card in the players hand
	G.hand[currentPlayer][2] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// ----------- TEST 11 : Test correct return statements for invalid input -----------
	printf("%s TEST 11: Correct return statements for invalid input\n", TESTCARD);
	result = playAdventurer(&testG, currentPlayer, 4);
	if (result == -1){
		asserttrue(1, 1);
	}
	else{
		asserttrue(0, 1);
	}

	// ----------- TEST 12: Test state stays same invalid input -----------
	printf("%s TEST 12: State says the same with invalid input\n", TESTCARD);
	result = playAdventurer(&testG, currentPlayer, 4);
	
	if (result == -1){

		for (i = 0; i <= treasure_map; i++){
			if (testG.supplyCount[i] != G.supplyCount[i]){
				asserttrue(0, 12);
				success = 0;
				break;
			}
			else{
				success = 1;
			}
		}
		if (success == 1){ // supplies staying the same
			asserttrue(1, 12);
		}
		else if (testG.coins != G.coins){
		asserttrue(0, 12);
		}
		else if (testG.numBuys != G.numBuys){
			asserttrue(0, 12);

		}
		else if (testG.numActions != G.numActions){
			asserttrue(0, 12);
		} 
		else if ((G.handCount[currentPlayer] + G.deckCount[currentPlayer] + G.discardCount[currentPlayer] + G.playedCardCount) != (
		testG.handCount[currentPlayer] + testG.deckCount[currentPlayer] + testG.discardCount[currentPlayer] + testG.playedCardCount))	{
			asserttrue(0, 12);
		}
		else if ((G.handCount[otherPlayer] + G.deckCount[otherPlayer] + G.discardCount[otherPlayer]) != (
		testG.handCount[otherPlayer] + testG.deckCount[otherPlayer] + testG.discardCount[otherPlayer])){
			asserttrue(0, 12);
		}
		else{
			asserttrue(1, 12);
		}
	}
	else{
		printf("TEST 12 could not be run due to unplanned input\n");
	}
	return 0;
}