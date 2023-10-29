#ifndef random_h
#define random_h

#include <time.h>
#include <stdlib.h>
#include "../player.h"
#include "../../verification/verification.h"
#include "../../verification/odd.h"
#include "../../verification/even.h"

// OK but TODO for human and pointer ?
void execute_random(Player players[2], Player p1, Player p2, int board[16][3]);

#endif