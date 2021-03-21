#include "catch2/catch.hpp"

namespace {
  std::uint64_t Fibonacci(std::uint64_t number)
  {
    return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
  }
} // namespace

TEST_CASE("Fibonacci")
{
  CHECK(Fibonacci(0) == 1);
  CHECK(Fibonacci(5) == 8);

#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)
  BENCHMARK("Fibonacci 20")
  {
    return Fibonacci(20);
  };

  BENCHMARK("Fibonacci 25")
  {
    return Fibonacci(25);
  };

  BENCHMARK("Fibonacci 30")
  {
    return Fibonacci(30);
  };

  BENCHMARK("Fibonacci 35")
  {
    return Fibonacci(35);
  };

  BENCHMARK_ADVANCED("Advanced Fibonacci 35")
  (Catch::Benchmark::Chronometer meter)
  {
    // set_up();
    meter.measure([] {
      return Fibonacci(35);
    });
  };
#endif
}
