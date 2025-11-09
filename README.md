# UIT C++ Homework

## TLDR;

- A simple Library Management System built in C++

- A group project built by Group 7 - IT001.Q110. All details are linked [here](https://github.com/Coder-Blue/btn1-llm).

| Thành viên          | MSSV     |
| ------------------- | -------- |
| Trần Ngô Anh Quân   | 25521506 |
| Đặng Hữu Huy        | 25520676 |
| Nguyễn Lê Vinh Hưng | 25520641 |
| Phan Bảo Huy        | 25520729 |

## My setup

- I'm using [Clang](https://github.com/mstorsjo/llvm-mingw) to build C/C++ app. You can use [GCC](https://sourceforge.net/projects/mingw/) instead.

## How to build

- On Windows

```bash
# Powershell

# GCC
New-Item -ItemType Directory -Force -Path output; g++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe

# Clang
New-Item -ItemType Directory -Force -Path output; clang++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output\app.exe
```

- On Mac/Linux

```bash
# sh

# GCC
mkdir -p output && g++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output/app

# Clang
mkdir -p output && clang++ -static -std=c++17 main.cpp library.cpp book.cpp user.cpp -o output/app
```

# How to run

- Run the `app.exe` in the `output` folder on Windows.

- Run this bash on Linux/MacOS:

```bash
#sh
./output/app
```