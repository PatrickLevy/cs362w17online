#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int asserttrue(int condition, char* message)
{
  if (!condition) {
    printf("\tError: %s\n", message);
    return 1;
  }

  return 0;
}


int main(int argc, char** argv) 
{
  struct gameState G,
                   testG;
  int i = 0,
      success = 1, 
      error_count = 0,
      error_total = 0,
      copper_count = 0,
      estate_count = 0, 
      seed = 0,
      k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy},
      bonus = 0;

  // Adventurer helper variables
  int currentPlayer = 1,
      drawntreasure = 0,
      cardDrawn,
      z = 0,
      temphand[MAX_HAND];

  seed = 1 + rand() % 10;
  // BEGIN INITIALIZATION TEST to gameState is correct
  printf("------------------------ Initializing Game----------------------\n");
  // Make sure initialize game returns success, if not exit
  success = initializeGame(2, k, seed, &G);
  asserttrue(success == 0, "Failed to Initialize Game");
  if ( success == -1 ) return 1; 

  // initialize game returns success, check values are what is expected

  // Make sure player count is correct
  error_count += asserttrue(G.numPlayers == 2, "Player Count Wrong");
  // Make sure supply counts are correct
  error_count += asserttrue(G.supplyCount[curse] == 10, "Curse Count Incorrect for 2 players");
  error_count += asserttrue(G.supplyCount[estate] == 8, "Estate Count Incorrect for 2 players");

  error_count += asserttrue(G.supplyCount[duchy] == 8, "Duchy Count Incorrect for 2 players");

  error_count += asserttrue(G.supplyCount[province] == 8, "Province Count Incorrect for 2 players");

  error_count += asserttrue(G.supplyCount[copper] == 46, "Copper Count Incorrect for 2 players");

  error_count += asserttrue(G.supplyCount[silver] == 40, "Silver Count Incorrect for 2 players");
  error_count += asserttrue(G.supplyCount[gold] == 30, "Gold Count Incorrect for 2 players");
  // Check Kingdom Card supply
  for (i = 0; i < 10; i++ ) {
    if (k[i] == great_hall || k[i] == gardens) {
      error_count += asserttrue(G.supplyCount[ k[i] ] == 8, "Deck Incorrect for 2 players");
    } else {
      error_count += asserttrue(G.supplyCount[ k[i] ] == 10, "Deck Incorrect for 2 players");
    }
  }

  // Make sure player deckcounts are correct
  // Player 1 is first so deckcount if 5 after drawing 5 cards, Player 2 should be 10
  error_count += asserttrue(G.deckCount[0] == 5 && G.deckCount[1] == 10, 
      "Player Deck Counts Incorrect");
  // Player 1 handCount is 5 and player 2 handCount is 0
  error_count += asserttrue(G.handCount[0] == 5 && G.handCount[1] == 0, "Player Handcount Incorrect");

  // Count Player 1s starting cards in hand and deck. SHould be 7 copper and
  // 3 estate
  for (i = 0; i < 10; i++) {
    if (i < G.handCount[0]) {
      if (G.hand[0][i] == copper) 
        copper_count++;
      else if (G.hand[0][i] == estate)
        estate_count++;
    }
    if (i < G.deckCount[0]) {
      if (G.deck[0][i] == copper)
        copper_count++;
      else if (G.deck[0][i] == estate)
        estate_count++;
    }
  }

  error_count += asserttrue(estate_count == 3 && copper_count == 7, "Player 1 starting Deck is Incorrect");
  estate_count = 0;
  copper_count = 0;
  // Count Player 2s starting cards, should be 7 copper and 3 estate
  for (i = 0; i < 10; i++) {
    if ( i < G.handCount[1] ) {
      if (G.hand[1][i] == copper)
        copper_count++;
      else if (G.hand[1][i] == estate)
        estate_count++;
    }
    if ( i < G.deckCount[1]) {
      if (G.deck[1][i] == copper)
        copper_count++;
      else if (G.deck[1][i] == estate)
        estate_count++;
    }
  }
  error_count += asserttrue(estate_count == 3 && copper_count == 7,
      "Player 2 starting Deck is incorrect");

  // Check that player 1s turn is initialized correctly
  error_count += asserttrue(G.outpostPlayed == 0 &&
      G.phase == 0 &&
      G.numActions == 1 &&
      G.numBuys == 1 &&
      G.playedCardCount == 0 &&
      G.whoseTurn == 0, "Player 1 Turn Initialized Incorrectly");

  // If error_count is still 0 then Game was initialized successfully
  if (error_count ==  0 )
    printf("Game Initiliazed Successfully\n");
  else
    printf("Game Initialization encountered %d errors\n", error_count); 

  printf("------------------------ Finished Initialization Section ----------------------\n");

  error_count = 0;

  printf("------------------------ Testing Adventurer Card ------------------------------\n");

  printf("Testing Adventurer, Player 2 deck not empty, contains copper and estate only");
  G.whoseTurn = 1;  // mark it as player 2's turn
  memcpy(&testG, &G, sizeof(struct gameState));

  success = cardEffect(adventurer, -1, -1, -1, &testG, 0, &bonus);


  while(drawntreasure < 2)
  {
    if (G.deckCount[currentPlayer] < 1) //if the deck is empty we need to shuffle discard and add to deck
    {
      shuffle(currentPlayer, &G);
    }
    drawCard(currentPlayer, &G);
    cardDrawn = G.hand[currentPlayer][G.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold )
      drawntreasure++;
    else
    {
      temphand[z]=cardDrawn;
      G.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while(z-1 >= 0)
  {
    G.discard[currentPlayer][G.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }

  error_count += asserttrue(success == 0, "Call to cardEffect for adventurer returned status failed");
  error_count += asserttrue(G.handCount[currentPlayer] == testG.handCount[currentPlayer], 
      "handCount does not match reference");
  seed = 0;
  copper_count = 0;
  for (i = G.handCount[currentPlayer]; i > G.handCount[currentPlayer]-2; i--) {
    if (G.hand[currentPlayer][i] != testG.hand[currentPlayer][i])
      seed++;
    cardDrawn = testG.hand[currentPlayer][i];
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      copper_count++;
  }

  error_count += asserttrue(seed == 0, "Top two cards in hand do not match reference");
  error_count += asserttrue(copper_count == 2, "Top two cards in hand are not currency");
  error_count += asserttrue(G.discardCount[currentPlayer] == testG.discardCount[currentPlayer],
      "discardCount does not match reference");

  if (error_count == 0)
    printf("\tAll Tests Successful, Player 2 deck not empty, contains copper and estate only\n\n");
  else
    printf("\t%d Tests Failed, Player 2 deck not empty, contains copper and estate only\n\n", error_count);

  error_total += error_count;
  error_count = 0;




  error_total += error_count;

  if (error_total == 0)
    printf("ALL TESTS SUCCESSFUL, Adventurer\n");
  else
    printf("%d TESTS FAILED, Adventurer\n", error_total);

  return 0; 
}


