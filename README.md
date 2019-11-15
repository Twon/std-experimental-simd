# std-experimental-simd
A reference implementation of std::experimental::simd, providing data parallel types in the C++ standard.  This provides an alternative implementation of std::experimantal::simd which targets cross compiler conformant for x86/x64 instruction set architectures.

# Alternative Implementation
At present, this author, is aware of 2 alternative existing implementations of std::experimental::simd.  These are:
- [std-simd](https://github.com/VcDevel/std-simd) is Matthias Kretz's implementation, which derives from the [Vc](https://github.com/VcDevel/Vc) library. Matthias has authored the papers proposing std::experimental::simd.  This implementation targets GCC.
- [dimsum](https://github.com/google/dimsum)

Alternative Vector Libraries
- [tsimd - Fundamental C++ SIMD types for Intel CPUs (sse to avx512)](https://github.com/ospray/tsimd)
- [C++ wrappers for SIMD intrinsics](https://github.com/QuantStack/xsimd)
- [libsimdpp - Portable header-only zero-overhead C++ low level SIMD library](https://github.com/p12tic/libsimdpp)
- [C++ vector class library](agner.org/optimize/#vectorclass)

# References
- [P0214R5]Matthias Kretz. P0214R5: Data-Parallel Vector Types & Operations. ISO/IECC++Standards Committee Paper. 2017.url:http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0214r5.pdf.
- [P0214R6]Matthias Kretz. P0214R6: Data-Parallel Vector Types & Operations. ISO/IECC++Standards Committee Paper. 2017.url:http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0214r6.pdf.
- [P0820R0]Tim Shen. P0820R0: Feedback on P0214R5. ISO/IEC C++Standards Com-mittee Paper. 2017.url:https://wg21.link/p0214r0.
- [1]Tutorial: Array Notation | Cilk Plus. Intel Corporation.url:https://www.cilkplus.org/tutorial-array-notation(visited on 01/11/2014

## Articles
- [SIMD Wrapper Libraries](https://cppcast.com/jeff-amstutz-simd-wrapper-libs/)
- [Building a C++ SIMD abstraction (1/N) – Motivation](https://jeffamstutz.io/2017/12/07/building-a-c-simd-abstraction-1-n-motivation/)
- [Building a C++ SIMD abstraction (2/N) – Status Quo (My Perspective)](https://jeffamstutz.io/2017/12/14/building-a-c-simd-abstraction-2-n-status-quo-my-perspective/)
- [Building a C++ SIMD Abstraction (3/N) – A Tour of ‘tsimd’](https://jeffamstutz.io/2018/01/02/building-a-c-simd-abstraction-3-n-a-tour-of-tsimd/)
- [Building a C++ SIMD Abstraction (4/N) – Type Traits Are Your Friend](https://jeffamstutz.io/2018/03/30/building-a-c-simd-abstraction-4-n-type-traits-are-your-friend/)
- [XSIMD](https://quantstack.net/xsimd.html)
- [Bye bye boost.simd, welcome xsimd](https://serge-sans-paille.github.io/pythran-stories/bye-bye-boostsimd-welcome-xsimd.html)

## Videos
- [CppCon 2018: Jefferson Amstutz “Compute More in Less Time Using C++ Simd Wrapper Libraries”](https://www.youtube.com/watch?v=8khWb-Bhhvs)
- [Joel Falcou, Mathias Gaunard: Practical SIMD acceleration with Boost.SIMD](https://www.youtube.com/watch?v=nxsBPjDTpZc)
- [An implementer's view of Boost.SIMD - Joel Falcou - Meeting C++ 2016](https://www.youtube.com/watch?v=QEywuJ122F4)
- [Joel Falcou, Boost.SIMD](https://www.youtube.com/watch?v=vf9wE9fIb0A)