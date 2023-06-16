#include<bits/stdc++.h>
#include "memory.hpp"
using namespace std;

void writeBack(pair<bitset<8>, bitset<32>> data, Memory memory){
  if (data.first.all() or data.first.none()){
    return;
  }
  memory.setRegister(data.first.to_ulong(), data.second);
}