# Field Calculator

A command-line calculator for working with elements of finite fields **Z(p)**, written in C.

## Features

- Compute the representation of any **integer** in a finite field Z(p)
- Compute the representation of a **fraction** (a/b) in a finite field Z(p)
- Input validation: checks that *p* is a positive prime number

## Requirements

- GCC compiler
- Standard C math library (`-lm`)

## Build & Run

```bash
gcc src/FieldCalculator.c src/main.c -lm -o Calc
./Calc
```

## Usage

1. Enter a prime number `p` — the order of the field
2. Choose the element type:
   - `0` — Fraction (a/b)
   - `1` — Integer
3. Enter the element value(s)
4. The program outputs the result in field Z(p)
5. Choose whether to run again or exit

### Example

```
Enter p value:
7
Choose your element type:
Fraction - 0
Integer - 1
1
Enter your element:
15
15 in field of 7 is: 1
```

## Project Structure

```
.
├── include/
│   └── FieldCalculator.h   # Function declarations and enum
└── src/
    ├── FieldCalculator.c   # Core logic
    └── main.c              # Entry point
```
