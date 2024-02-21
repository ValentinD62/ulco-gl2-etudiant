#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}

int fiboIterative(int n){
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 0; i < n; i++){
        c = a;
        a = b;
        b += c;
    }
    return a;
}


#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {
    m.def("fibo_naive", &fiboNaive, "Fibo Naive");
    m.def("fibo_iterative", &fiboIterative, "Fibo Iterative");

}

