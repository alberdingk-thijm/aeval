#include "horn/BndExpl.hpp"

using namespace ufo;
using namespace std;

int main (int argc, char ** argv)
{
  if (argc == 1){
    outs() << "At least an input file should be given\n";
    return 0;
  }
  
  int lower = 0;          //default
  int upper = 1000;       //default
  
  if (argc > 2) lower = atoi(argv[1]);
  if (argc > 3) upper = atoi(argv[2]);
  
  getItpsAndCheck(string(argv[argc-1]), lower, upper);
  
  return 0;
}
