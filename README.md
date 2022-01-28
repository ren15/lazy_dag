# lazy_dag

This project is intended to test the performance difference 
between creating DAG with 
- handwritten every expression  
- Use virtual inheritence  
- Use expression template   
    https://github.com/asavine/CompFinance/tree/AADbook
- Lazy string concatenation
    Functional Programming in C++

## TODO:

1. DRY on compiler selection in scripts.
2. expression_template using ranges.


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

### ranges

#### Use ranges-v3 to replace expression templates.   

https://gieseanw.wordpress.com/2019/10/20/we-dont-need-no-stinking-expression-templates/?utm_source=pocket_mylist

https://godbolt.org/z/M7WaxjWsv

https://godbolt.org/z/sMPvEbW3j

#### ranges-v3/std::ranges lazy examples.  

https://www.modernescpp.com/index.php/c-20-functional-patterns-with-the-ranges-library?utm_source=pocket_mylist


### Check boost.proto 
DONE: Too old. 

### Use boost.yap instead. 
https://www.boost.org/doc/libs/1_74_0/doc/html/boost_yap/manual.html  
Maybe also repalcable by ranges.

    
### Tensorflow uses lazy evaluation

https://solegaonkar.github.io/tfLazyExecution.html

https://www.tensorflow.org/guide/basics


## Rust

### Expression template in Rust
https://stackoverflow.com/questions/70139404/expression-template-implementation-in-rust-like-in-boostyap

crate xpr https://github.com/joergbrech/xpr

Rust is lacking template specialization, this part should still better be handled by C++.   
Use FFI if necessary.