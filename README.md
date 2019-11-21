# About

Projects for students in Princeton University.

# Installation

Compiles with gcc-5 (on Linux) and clang-700 (on Mac). Assumes preinstalled Gmp and Boost (libboost-system1.55-dev) packages.

* `cd aeval ; mkdir build ; cd build`
* `cmake ../`
* `make` to build dependencies (Z3 and LLVM)
* `make` to build your project

The binaries can be found in `build/tools/`

# Understanding the API

```cpp
// creation of a variable with new name that has a type of other variable:
Expr new_name = mkTerm<string> (fresh_string_name, m_efac);
Expr new_var = cloneVar(origVar, new_name));
```

```cpp
// renaming old_var by new_var in an expression:
Expr newExpr = replaceAll(oldExpr, old_var, new_var);
```

```cpp
// conjoining all expressions from a vector (or a set):
ExprVector vec;
Expr conj = conjoin(vec, m_efac);
```

```cpp
// obtaining the body, source, and destination variables of a CHC:
HornRuleExt& hr = ruleManager.chcs[X];
Expr body = hr.body;
ExprVector& src = hr.srcVars;
ExprVector& dst = hr.dstVars;
```
