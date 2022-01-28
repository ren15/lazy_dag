# lazy_dag

This project is intended to test the performance difference 
between creating DAG with 
- handwritten every expression  
- Use virtual inheritence  
- Use expression template   
    https://github.com/asavine/CompFinance/tree/AADbook
- Lazy string concatenation
    Functional Programming in C++


## tools to use 

``gcc, clang, clang-format, clang-tidy, cppcheck, CMake, conan, google benchmark``

## C++

To illustrate lazy evaluation,

```c++
Vector<int,10000> v;
ans = v * 10 * 20 * 30 * 40;
```
If `vector * scaler` takes 1 ms,  
the naive approach takes 4 ms,  
but the lazy approach takes only 1 ms.  

Check `src/ranges_impl/vec.hpp`

1. Implement operator* for `Vector<T,N>` as eager evaluation.

2. Use ranges to implement operator* for `Vector<T,N>` as lazy evaluation.

### Check range-v3

Use ranges-v3 to replace expression templates.  
https://gieseanw.wordpress.com/2019/10/20/we-dont-need-no-stinking-expression-templates/?utm_source=pocket_mylist

https://godbolt.org/z/M7WaxjWsv

https://godbolt.org/z/sMPvEbW3j

### Check boost.proto DONE: Too old. 

### Use boost.yap instead. 
    https://www.boost.org/doc/libs/1_74_0/doc/html/boost_yap/manual.html

    
### Tensorflow uses lazy evaluation

https://solegaonkar.github.io/tfLazyExecution.html

https://www.tensorflow.org/guide/basics


## Expression template in Rust
    https://stackoverflow.com/questions/70139404/expression-template-implementation-in-rust-like-in-boostyap

    xpr https://github.com/joergbrech/xpr