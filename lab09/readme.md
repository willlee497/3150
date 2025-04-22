# Lab: Node Cycles and `weak_ptr`s

**Author:** Will Lee  
**Course:** CSE 3150  
**Date:** April 22, 2025  
**Instructor:** Phillip G. Bradford

## 🧠 Overview

This lab demonstrates how to manage memory safely in circular linked list structures using `shared_ptr` and `weak_ptr` in C++. We explore the behavior of smart pointers in cyclic references, comparing two implementations:
- One using only `shared_ptr` (which causes memory leaks),
- One using `shared_ptr` + `weak_ptr` (which properly deallocates memory).

## 🏗️ Files Included

- `Node.cpp` — Main implementation and unit testing file (uses `doctest`)
- `doctest.h` — Lightweight header-only testing framework (must be in the same directory or include path)
- `README.md` — You're reading it!
- `lab_report.pdf` — One-page written lab summary
- `demo_video.mp4` — (to be recorded) Console demo showing both list behaviors

## ⚙️ How to Compile

You must use C++17 and link OpenSSL if needed (not required here).

g++ -std=c++17 -I. Node.cpp -o node_app
./node_app