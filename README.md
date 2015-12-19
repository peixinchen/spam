# spam
利用C/C++扩展Python示例

## 代码示例来源
1. [Extending Python with C or C++](https://docs.python.org/2/extending/extending.html)
2. [Building C and C++ Extensions with distutils](https://docs.python.org/2/extending/building.html#building)

## 注意事项
文档中基本都有说明，但为了方便起见，还是提炼在这里，不一定是全的。

1. 这种方式只能用在CPython上

  ```
  Note

  The C extension interface is specific to CPython, and extension modules do not work on other Python implementations. In many cases, it is possible to avoid writing C extensions and preserve portability to other implementations. For example, if your use case is calling C library functions or system calls, you should consider using the ctypes module or the cffi library rather than writing custom C code. These modules let you write Python code to interface with C code and are more portable between implementations of Python than writing and compiling a C extension module. 
  ```

2. \#include \<Python.h\>必须在第一个进行include

  ```
  Note

  Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included. 
  ```

