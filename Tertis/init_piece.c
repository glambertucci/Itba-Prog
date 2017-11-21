#include "init_piece.h"

PIECE  init_piece (void)
{
    static PIECE next_p;
    next_p.type  = rand() %7 +1;
    next_p.state = CAYENDO;
    return next_p;
   
}
