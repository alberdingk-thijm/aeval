#ifndef ANNOCHECK__HPP__
#define ANNOCHECK__HPP__

#include "Horn.hpp"
#include "CandChecker.hpp"
#include "ae/SMTUtils.hpp"

/* Template for P6 */

using namespace std;
using namespace boost;
namespace ufo
{
  class AnnoCheck
  {
    private:

    HornRuleExt* tr;
    HornRuleExt* fc;
    HornRuleExt* qr;

    public:

    AnnoCheck () {}

    void checkPrerequisites (CHCs& r)
    {
      if (r.decls.size() > 1)
      {
        outs() << "Nested loops not supported\n";
        exit(0);
      }

      if (r.chcs.size() != 3)
      {
        outs() << "Please provide a file with exactly three rules\n";
        exit(0);
      }

      for (auto & a : r.chcs)
        if (a.isInductive) tr = &a;
        else if (a.isFact) fc = &a;
        else if (a.isQuery) qr = &a;

      if (tr == NULL)
      {
        outs() << "TR is missing\n";
        exit(0);
      }

      if (fc == NULL)
      {
        outs() << "INIT is missing\n";
        exit(0);
      }

      if (qr == NULL)
      {
        outs() << "BAD is missing\n";
        exit(0);
      }
    }

    void checkInvariant (CHCs& r, Expr cand)
    {
      CandChecker cc(r.m_efac, fc, tr, qr);

      bool res;

      res = cc.checkInitiation(cand);
      if (!res)
      {
        outs() << "\nInitiation is not fulfilled\n";
        outs() << "Counterexample:\n  " << *cc.getModel(fc->dstVars) << "\n";
        return;
      }

      res = cc.checkInductiveness(cand);
      if (!res)
      {
        outs() << "\nInductiveness is not fulfilled\n";
        outs() << "Counterexample:\n  " << *cc.getModel(tr->srcVars) << "\n";
        return;
      }

      res = cc.checkSafety();
      if (!res)
      {
        outs() << "\nLemma learned!\n";
        outs() << "Safety is not fulfilled\n";
        outs() << "Counterexample:\n  " << *cc.getModel(qr->srcVars) << "\n";
        return;
      }

      outs() << "Success!\n";
    }
  };

  inline void annotationCheck(const char * chcfile, const char * invfile)
  {
    ExprFactory efac;
    EZ3 z3(efac);
    CHCs ruleManager(efac, z3);
    ruleManager.parse(string(chcfile));
    AnnoCheck a;
    a.checkPrerequisites(ruleManager);
    outs () << "Program encoding:\n";
    ruleManager.print();

    Expr cand = z3_from_smtlib_file (z3, invfile);
    outs() << "User-provided annotation:\n  " << *cand << "\n";

    a.checkInvariant(ruleManager, cand);

    // TODO: replace "checkInvariant" by a more intelligent algorithm to inductive subset extraction
  }
}

#endif
