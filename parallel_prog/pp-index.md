# Parallel Programming for Numerical Computing

**Author: Alessandro Renzi - First draft date: 07/07/2025 - License: GPL3**

0. **Prolegomena**

- When possibile and useful I will provide examples in different programming languages

- The programming language I will going to use are the ones that I more or less know, and usually the programming languages useful for numerical computing

- **At some point** I will provide a page that by introducing basic concepts of computation will explain why I will never going to explain or use concepts of Object Oriented Programming -> The consequences of not using OOP is that, despite the fact that c and c++ are very different programming languages, without OOP they are much more similar and so I will only show examples in c with the certainty that translating it in c++ will be very easy. What do I mean by **"similar"**? -> When I program in c++ I use the standard library or objects provided by other libraries, but I do not create new ones. So for example in c you allocate memory with `malloc` but in c++ you are going to use `new` for allocating the objects (in c++ is much more practical to use the class `<vector>` or `<valarray>` [???](https://www.reddit.com/r/cpp/comments/17ux1o5/why_is_stdvalarray_so_underrated/) instead of the pointer to the memory like c). Yet again, I do not create new `class` and only use imperative programming in c++ (or any other programming language I use).

-  The codes that you can find here are not the most optimized and general version you can find on internet. Those codes have the only pourpose of being useful for teaching some ideas. Most of the time you will find the best optimal version of many, if not all, of the codes showed here in already super-optimied mathematical libraries (e.g. LAPACK or similar).

---

We start the jurney of learning parallel programming for numerical computing by introducing some (serial) codes that will be optimized by transforming them in a parallel fashion durign the course of the "lectures".

1. [Serial Basic Codes](./pp-serial_basic_codes.md)


\[[Main](../README.md)\]
