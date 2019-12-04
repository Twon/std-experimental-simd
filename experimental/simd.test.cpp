#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <experimental/simd>

using namespace std::experimental;

/*! Helper function to capture constexpr results in catch test reporting.
    \note
        Credit to Jason Turner: https://twitter.com/lefticus/status/980530307580514304
    \tparam B
        Compile time condition.
    \return
        The compile time condition result.
 */
template<bool B>
constexpr bool static_test()
{
    static_assert(B);
    return B;
}


TEST_CASE("Test ABI type traits", "[simd.abi.traits]")
{
    REQUIRE(static_test<is_abi_tag<simd_abi::scalar>::type::value>());
    REQUIRE(static_test<is_abi_tag<simd_abi::sse_register>::type::value>());
    REQUIRE(static_test<is_abi_tag<simd_abi::avx_register>::type::value>());
    REQUIRE(static_test<is_abi_tag<simd_abi::avx512_register>::type::value>());
}