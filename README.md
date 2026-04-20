# Libasm

A library of essential C string and I/O functions implemented in x86-64 assembly language.

**Author:** Guillaume Cools  
**School:** 42  
**Project:** Libasm

## Overview

This project implements common libc functions in pure assembly (NASM syntax), demonstrating low-level programming concepts and syscall handling on x86-64 architecture.

## Functions

### String Operations

- **`ft_strlen`** - Calculate the length of a string
- **`ft_strcpy`** - Copy a string to a destination buffer
- **`ft_strcmp`** - Compare two strings lexicographically
- **`ft_strdup`** - Allocate and duplicate a string

### I/O Operations

- **`ft_write`** - Write data to a file descriptor (syscall)
- **`ft_read`** - Read data from a file descriptor (syscall)

## Building

```bash
make         # Build the library
make clean   # Remove object files
make fclean  # Remove object files and library
make re      # Clean rebuild
```

## Testing

Compile and run the test program:

```bash
make
./libasm.a
```

The test program compares the behavior of each custom function against the standard C library equivalents.

## Architecture

- **Assembly files** (`.s`) - Core function implementations using NASM syntax
- **Makefile** - Builds assembly files with `nasm` and C files with `gcc`
- **main.c** - Comprehensive test suite validating all functions

## Compiler Requirements

- `gcc` - C compiler for building
- `nasm` - Assembler for x86-64 compilation
