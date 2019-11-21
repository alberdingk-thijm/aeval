#ifndef BNDEXPL__HPP__
#define BNDEXPL__HPP__

#include "Horn.hpp"
#include "ae/AeValSolver.hpp"

using namespace std;
using namespace boost;
namespace ufo
{
  class BndExpl
  {
    private:

    ExprFactory &m_efac;
    CHCs& ruleManager;
    // TODO: possibly other fields...

    public:
    // TODO: helper methods, e.g. conversion from a trace to an SMT expression

    // Explore the set of possible traces between the current bound and the given bound,
    // and return true if no trace is satisfiable.
    bool exploreTraces(int cur_bnd, int bnd, bool print = false) {
      bool unsat = true;

      while (unsat && cur_bnd <= bnd)
      {
        // TODO: explore traces
        // TODO: check if any of the traces are satisfiable
      }
      if (print) {
        // TODO: some diagnostic information
      }
      return unsat;
    }
    // TODO

    inline void unrollAndCheck(string smt, int bnd1, int bnd2)
    {
      ExprFactory m_efac;
      EZ3 z3(m_efac);
      CHCs ruleManager(m_efac, z3);
      ruleManager.parse(smt);
      // TODO: Initialize the class with the CHCs
      // TODO: Explore the possible traces between the two bounds
      // TODO: report something? (might need to change the return type)
    }
  }
}

#endif
