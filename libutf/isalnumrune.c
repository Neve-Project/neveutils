/* Automatically generated by mkrunetype.awk */
#include "../include/utf.h"
#include "runetype.h"

int isalnumrune(Rune r) { return isalpharune(r) || isdigitrune(r); }
