#ifndef verification_h
#define verification_h

#include <stdbool.h>

// OK
typedef struct Verification
{
    bool (*satisfy)(int nb);
} Verification;

#endif
