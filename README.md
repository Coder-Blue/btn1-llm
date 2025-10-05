# UIT C++ Homework

## TLDR;

- A simple Library Management System build in C++

## My setup

- I'm using [Clang](https://github.com/mstorsjo/llvm-mingw) to build C/C++ app. You can use [GCC](https://sourceforge.net/projects/mingw/) instead.

## How to build

- On Windows

```bash
# Powershell

# GCC
New-Item -ItemType Directory -Force -Path output; g++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe

# Clang
New-Item -ItemType Directory -Force -Path output; clang++ -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe
```

- On Mac/Linux

```bash
# sh

# GCC
if not exist output mkdir output & g++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe

# Clang
if not exist output mkdir output & clang++ -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe
```