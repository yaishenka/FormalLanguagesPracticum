/** @author yaishenka
    @date 2019-11-08 */
#pragma once
#include "State.hpp"
#include <vector>
#include <string>
#include <optional>

namespace automate {

class IncorrectRegexp: public std::exception {
  const char* what() const noexcept override {
    return "Incorrect regexp";
  }
};

class Automate {
 public:
  static std::optional<size_t> GetShortestWord(const std::string& regexp, char letter, int max_letters);

 private:
  static State ProcessRegexp(const std::string& regexp, char letter, int max_letters);
};

}  // namespace automate
