#ifndef _TYPES_H
#include "types.hpp"
#endif

bitset<32> instructionFetch(int PC, Memory *memory){
  return memory->getInstruction(PC);
}