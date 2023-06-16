#include<bits/stdc++.h>
#include "memory.hpp"
using namespace std;

bitset<32> instructionFetch(int PC, Memory memory){
  return memory.getInstruction(PC);
}