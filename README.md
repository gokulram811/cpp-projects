# Matrix Math Toolkit (C++ Hybrid)

A high-performance linear algebra library that combines custom C++ implementations with the **Eigen** library for advanced mathematical operations.

## ✨ Features
* **Custom Logic:** Transpose, Trace, and Matrix Generators.
* **Eigen Integration:** Rank detection, Determinant calculation, and Pseudo-inverse.
* **Property Checks:** Positive Definite (PD) and Negative Definite (ND) matrix verification.

## 🛠️ Requirements
* **LLVM/Clang** compiler.
* **Eigen 5.0.1** (Header-only library).

## 🚀 How to Compile and Run
Ensure the `eigen-5.0.1` folder is in the project root, then run:

```bash
clang++ -I include/linalg -I eigen-5.0.1 matrix_run.cpp -o matrix_tool.exe -std=c++17 -O3
./matrix_tool.exe