# std-experimental-simd

[![travis][badge.travis]][travis]
[![appveyor][badge.appveyor]][appveyor]
[![codecov][badge.codecov]][codecov]
[![language][badge.language]][language]
[![license][badge.license]][license]
[![issues][badge.issues]][issues]

[badge.travis]: https://img.shields.io/travis/twon/std-experimental-simd/master.svg?logo=travis
[badge.appveyor]: https://img.shields.io/appveyor/ci/twon/std-experimental-simd/master.svg?logo=appveyor
[badge.codecov]: https://img.shields.io/codecov/c/github/twon/std-experimental-simd/master.svg?logo=codecov
[badge.language]: https://img.shields.io/badge/language-C%2B%2B20-yellow.svg
[badge.license]: https://img.shields.io/badge/license-MIT-blue.svg
[badge.issues]: https://img.shields.io/github/issues/twon/std-experimental-simd.svg

[travis]: https://travis-ci.org/twon/std-experimental-simd
[appveyor]: https://ci.appveyor.com/project/twon/std-experimental-simd
[codecov]: https://codecov.io/gh/twon/std-experimental-simd
[language]: https://en.wikipedia.org/wiki/C%2B%2B20
[license]: https://en.wikipedia.org/wiki/MIT_License
[issues]: http://github.com/twon/std-experimental-simd/issues

A reference implementation of std::experimental::simd, providing data parallel types in the C++ standard.  This provides an alternative implementation of std::experimantal::simd which targets cross compiler conformant for x86/x64 instruction set architectures.

# Alternative Implementation
At present, this author, is aware of 2 alternative existing implementations of std::experimental::simd.  These are:
- [std-simd](https://github.com/VcDevel/std-simd) is Matthias Kretz's implementation, which derives from the [Vc](https://github.com/VcDevel/Vc) library. Matthias has authored the papers proposing std::experimental::simd.  This implementation targets GCC.
- [dimsum](https://github.com/google/dimsum)

# Alternative Vector Libraries
- [tsimd - Fundamental C++ SIMD types for Intel CPUs (sse to avx512)](https://github.com/ospray/tsimd)
- [C++ wrappers for SIMD intrinsics](https://github.com/QuantStack/xsimd)
- [libsimdpp - Portable header-only zero-overhead C++ low level SIMD library](https://github.com/p12tic/libsimdpp)
- [C++ vector class library](https://www.agner.org/optimize/#vectorclass)

# References
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0214r9.pdf

- [P0214R9: Data-Parallel Vector Types & Operations. Matthias Kretz. ISO/IECC++Standards Committee Paper. 2018.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0214r9.pdf)
- [P0214R6: Data-Parallel Vector Types & Operations. Matthias Kretz. ISO/IECC++Standards Committee Paper. 2017.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0214r6.pdf)
- [P0214R5: Data-Parallel Vector Types & Operations. Matthias Kretz. ISO/IECC++Standards Committee Paper. 2017.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0214r5.pdf).
- [P0851R0: simd<T> is neither a product type nor a container type. Matthias Kretz. ISO/IECC++Standards Committee Paper. 2017.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0851r0.pdf)
- [P0820R0: Feedback on P0214R5. Tim Shen. ISO/IEC C++Standards Committee Paper. 2017.](https://wg21.link/p0214r0)
- [P0820R1: Feedback on P0214R6. Tim Shen. ISO/IEC C++Standards Committee Paper. 2017.](https://wg21.link/p0214r1)
- [Tutorial: Array Notation | Cilk Plus. Intel Corporation.](https://www.cilkplus.org/tutorial-array-notation)
- [N4454: SIMD Types Example: Matrix Multiplication. Matthias Kretz. ISO/IEC C++Standards Committee Paper, 2014](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4454.pdf)
- [N4184: SIMD Types: The Vector Type & Operations. Matthias Kretz. ISO/IEC C++Standards Committee Paper, 2014](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4184.pdf)
- [N4185: SIMD Types: The Mask Type & Write-Masking. Matthias Kretz. ISO/IEC C++Standards Committee Paper, 2014](http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4185.pdf)
- [N4395: SIMD Types: ABI Considerations. Matthias Kretz. ISO/IEC C++Standards Committee Paper, 2015](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4395.pdf)

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

## Presentations
[SSE/SSE2 Toolbox SSE/SSE2 Toolbox Solutions for Solutions for Real-Life SIMD Life SIMD Problems Problems](https://www.gamasutra.com/features/gdcarchive/2001E/Alex_Klimovitski3.pdf)

## Academic Papers
- [Emmerald : A Fast Matrix-Matrix Multiply Using Intel’s SSE Instructions](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.23.6754&rep=rep1&type=pdf)
- [Source code transformations for efficient SIMD code generation](https://core.ac.uk/download/pdf/41768325.pdf)