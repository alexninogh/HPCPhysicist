# Set up a new environment

I'm following [Modern Julia Workflows](https://modernjuliaworkflows.org/) and [Julialang](https://julialang.org/contribute/developing_package/) guide for developing a package.

**NOTE**: the default environment must be as light as possible, all the "heavy" packages should be installed in the project environment (for example Plots, however it is advised to split environment with the packages necessary to run the code, with the packages to analyze the output of the code). For the moment I will debug, profile and test packages with the default environment.

- Install Julia with `juliaup`

- Start creating a `startup.jl` file with some useful packages for REPL (OhMyREPL and NumberedPrompt) and general project management (Revise and PkgTemplates).:

```julia
import StartupCustomizer
StartupCustomizer.add(StartupCustomizer.Revise(), StartupCustomizer.OhMyREPL(), StartupCustomizer.NumberedPrompt(), StartupCustomizer.PkgTemplates())
```

- To help activate the correct environment, add the following to your `startup.jl` (*NOTE:* for Windows the location is `C:\Users\USERNAME\.julia\config\startup.jl`):

```julia
# Automatically activate project inside directory
using Pkg
if isfile("Project.toml") && isfile("Manifest.toml")
    Pkg.activate(".")
end
```

\[[Index](./julia-index.md)\] \[[Next](./Create_new_package.md)\]