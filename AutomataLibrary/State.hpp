/** @author yaishenka
    @date 2019-11-10 */
#pragma once
#include <vector>
#include <exception>

namespace automate {

class NotCompatibleRegexps: public std::exception {
  const char* what() const noexcept override {
    return "Not compatible regexps";
  }
};

class State {
 public:
  /*!
   * Construct state from one symbol
   * @pre symbol \in alphabet
   */
  explicit State(char symbol, char letter_to_collect, int letters_count);
  State(const State&) = default;
  State(State&&) noexcept = default;
  State& operator=(const State&) = default;
  State& operator=(State&&) noexcept = default;

  bool IsCompatible(const State& other_state);

  /*!
   * Access to min length of string, that contains letters_count
   */
  size_t& operator[](const size_t& letters_count);
  const size_t& operator[](const size_t& letters_count) const;

  /*!
   * (r1 + r2)
   */
  const State operator+(const State& other_automate);

  /*!
   * (r1 * r2)
   */
  const State operator*(const State& other_automate);

  /*!
   * r^k = (r + rr + rrr + ... + r^k)
   */
  const State operator^(size_t power);

  static constexpr size_t impossible_length_ = static_cast<size_t>(10e9);
 private:
  char letter_to_collect_;
  int letters_count_;

  std::vector<size_t> min_string_length_;
};
}

