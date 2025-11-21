# Lighter Coin Detection Using Divide and Conquer (C Program)

This project implements a simple divide-and-conquer method to identify a lighter defective coin among a set of coins. All coins are assumed to have the same normal weight except one that is lighter.

## Overview

The program:

- Accepts `n` coin weights from the user  
- Uses a weighing function to compare the total weight of two halves  
- Recursively narrows down to the lighter coin  
- Prints the index and weight of the defective coin, if one exists

This demonstrates how binary splitting can be used to detect a counterfeit coin efficiently.

## How It Works

### `weigh()`
Compares the sum of weights in the left half and right half:
- Returns `-1` if left side is lighter  
- Returns `1` if right side is lighter  
- Returns `0` if both sides balance  

### `findLighterCoin()`
A recursive function that:
- Splits the set of coins into halves  
- Uses `weigh()` to decide which half contains the lighter coin  
- Stops when only one coin remains  

### Normal Weight Assumption
The first coin's weight is treated as the reference normal weight.

## Compilation

Use GCC or any C compiler:

```bash
gcc lighter_coin.c -o lighter_coin
