#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>
using fmt::print;

// https://github.com/lukas-blecher/LaTeX-OCR?tab=readme-ov-file

int main(int argc, char *argv[]) {
  print("Hello, {}!\n", "world");
  auto v = std::vector<int>{1, 2, 3};

  print("{}\n", v);
  return 0;
}
