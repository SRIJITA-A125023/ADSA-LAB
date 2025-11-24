# Function Growth Comparator in C

This project evaluates and compares the growth rates of several mathematical functions by computing their values at a large input size (`n = 102573`). The program then sorts the functions based on their computed values and prints them in increasing order.

## Overview

The program defines twelve different mathematical functions, each representing a different growth rate. These range from logarithmic and polynomial to exponential forms.

It computes the value of each function at `N = 102573`, stores them in a struct array, sorts them using `qsort`, and prints the results.

This is useful for studying asymptotic behavior and getting an intuition for how different functions scale.

## Functions Included

The code compares the following functions:

- `n log₂(n)`
- `12 √n`
- `1/n`
- `n^(log₂ n)`
- `100n² + 6n`
- `n^0.51`
- `n² - 324`
- `50 √n`
- `2n³`
- `3ⁿ`
- `2³² * n`
- `log₂ n`

## How It Works

1. Each function is computed at the constant `N`.
2. Each result is stored in a `Function` struct with a label and value.
3. All functions are sorted using `qsort`.
4. The sorted list is printed, showing approximate growth comparison.

## Build and Run

### Compile

```bash
gcc main.c -o growth -lm
