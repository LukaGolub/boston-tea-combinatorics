# Boston Tea Party Combinatorics (Generating Functions)

A C++ program that counts the number of distinct ways to select `n` tea bags from five types of tea, each with its own (optionally unlimited) supply limit, using polynomial multiplication to evaluate a generating function.

## Description

This program solves a classic combinatorics problem, framed as the "Citizens of Boston" tea party: given five types of tea (Bohea, Congou, Souchong, Singlo, and Hyson), each available in a limited quantity `a`, `b`, `c`, `d`, `e` (or unlimited, denoted by `-1`), how many distinct ways are there to select a total of `n` tea bags? It answers this by building the generating function `(1 + x + ... + x^a)(1 + x + ... + x^b)(1 + x + ... + x^c)(1 + x + ... + x^d)(1 + x + ... + x^e)` as a polynomial (via repeated array-based polynomial multiplication) and reading off the coefficient of `x^n`, which equals the number of valid selections.

## How It Works

- Each tea type is represented as a "polynomial" (an array) where index `i` is a coefficient of `x^i`: coefficient `1` for every power from `0` up to that tea's supply limit (or up to `n` if unlimited).
- Polynomials are multiplied pairwise by convolution (nested loops summing exponents and accumulating coefficient products), combining them in stages:
  1. `A x B` (Bohea x Congou)
  2. `C x D` (Souchong x Singlo)
  3. `(A x B) x (C x D)`
  4. `[(A x B) x (C x D)] x E` (Hyson)
- The final answer is the coefficient of `x^n` in the fully expanded product, i.e. `poljeAxBxCxDxE[n]`.
- A supply limit of `-1` for any tea type is treated as unlimited, capped at `n` (since using more than `n` bags of any single tea would already exceed the target total).

## Requirements

- A C++ compiler (e.g. `g++`) supporting C++11 or later

## Build

```bash
g++ -O2 -o tea_combinatorics tea_combinatorics.cpp
```

## Usage

```bash
./tea_combinatorics
```

The program prompts for each parameter in turn:

```
Unesite broj vrecica caja Bohea (parametar a):     # Enter number of Bohea tea bags (parameter a):
Unesite broj vrecica caja Congou (parametar b):    # Enter number of Congou tea bags (parameter b):
Unesite broj vrecica caja Souchong (parametar c):  # Enter number of Souchong tea bags (parameter c):
Unesite broj vrecica caja Singlo (parametar d):    # Enter number of Singlo tea bags (parameter d):
Unesite broj vrecica caja Hyson (parametar e):     # Enter number of Hyson tea bags (parameter e):
Unesite broj n:                                    # Enter the number n:
```

Enter `-1` for any tea's parameter to mark that tea as available in unlimited supply. It then prints the number of distinct tea-selection combinations totaling `n` bags:

```
Gradjani Bostona mogu napraviti <broj> razlicitih cajanki
```
("The citizens of Boston can make `<count>` different tea selections")

### Example

From the comment in the source (`1 6 -1 1 0 5`):

```
a = 1, b = 6, c = -1 (unlimited), d = 1, e = 0, n = 5
```

## Constraints

- `MAX` is fixed at `15000` — the maximum supported value for `n` and for any individual supply limit.
- Runtime is dominated by the `(A x B) x (C x D)` and subsequent `x E` convolution steps, each of which is `O(MAX^2)`, so very large values of `n`/`MAX` will be slow; this is an educational/demonstration implementation rather than an optimized one (an FFT-based or truncated convolution would scale much better).

## License

Feel free to use, modify, and distribute this project. Consider adding an explicit license file (e.g. MIT) if you plan to share it publicly.
