# Create a new Package

Example will generate the Needlets package.

NOTE: Revise.jl is always assumed loaded from julia startup script!

1. Start Julia REPL, then
```julia=
#Only the first time
using Pkg
Pkg.generate("Needlets")
Pkg.activate("./Needlets")
```
Later launch Julia REPL inside the just created `Needlets` directory, then simply `activate .` from the Pkg environment.

2. Start another Julia REPL that will serve as development environment (I call it simply `develop`, and use for all my projects)
```julia=
using Pkg
Pkg.activate("./develop")
Pkg.develop(path="../Needlets")
using Needlets
```
Now you can start developing the package!

\[[Back](Setup_new_environment.md)\] \[[Index](./julia-index.md)\] <!-- \[[Next](./01-Developing_a_package.md)\] -->
