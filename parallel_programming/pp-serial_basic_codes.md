# Some Serial Basic Codes

## Before starting: some notation

-  **array** -> the informatics data structure, [see](https://en.wikipedia.org/wiki/Array_(data_structure)).
  - used to implement mathematical objects like vectors, matrices, tensors, or other kinds of multi-dimensional "tables" (e.g. [lattice](https://en.wikipedia.org/wiki/Lattice_(group)))
  - an array could have multiple dimensions (also called **rank** not to be confused with the [rank of a matrix](https://en.wikipedia.org/wiki/Rank_(linear_algebra)): that is the maximal number of linearly independent columns of a matrix)
    - e.g. the mathematical structure called matrix in computer is usually represented with a rank-2 array
  - array are addessed by one or multiple indeces (depending of the dimensions or rank of the array)
  - array could have
    - 0-based indexing (The first element of the array is indexed by subscript of 0.) -> This is the default for programming languages like: c, c++
    - 1-based indexing (The first element of the array is indexed by subscript of 1.)
    - n-based indexing (The first element of the array is indexed by subscript of n. Where n is an integer)


## AXPY: constant times a vector plus a vector

[AXPY](https://www.netlib.org/lapack/explore-html/d5/d4b/group__axpy.html) is a sort of acronym for memorizing the operation of vector $\vec{x}$ multiplying a scalar $a$ and summing another vector $\vec{y}$, that is $\vec{d} = a \vec{x} + \vec{y}$ where $\vec{d}$ is the output vector.

Depending on the **type** of the vectors involved you can have daxpy (double precision) or caxpy (complex) etc.



\[[Index](./pp-index.md)\]
