#include "State.hpp"
#include <stdexcept> 
using namespace automate;

State::State(char symbol, char letter_to_collect, int letters_count)
    : min_string_length_(letters_count + 1, impossible_length_),
      letter_to_collect_(letter_to_collect),
      letters_count_(letters_count) {
  if (letter_to_collect == symbol && letters_count > 0) {
    min_string_length_[1] = 1;
  } else {
    min_string_length_[0] = 1;
  }
}

bool State::IsCompatible(const State& other_state) {
  return other_state.letters_count_ == letters_count_ &&
      other_state.letter_to_collect_ == letter_to_collect_;
}

size_t& State::operator[](const size_t& letters_count) {
  if (letters_count > letters_count_) {
    throw std::out_of_range("Automate");
  }

  return min_string_length_[letters_count];
}

const size_t& State::operator[](const size_t& letters_count) const {
  if (letters_count > letters_count_) {
    throw std::out_of_range("Automate");
  }

  return min_string_length_[letters_count];
}

const State State::operator+(const State& other_automate) {
  if (!IsCompatible(other_automate)) {
    throw NotCompatibleRegexps();
  }

  auto result = *this;
  for (int i = 1; i <= letters_count_; ++i) {
    result[i] = std::min((*this)[i], other_automate[i]);
  }

  return result;
}

const State State::operator*(const State& other_automate) {
  if (!IsCompatible(other_automate)) {
    throw NotCompatibleRegexps();
  }

  auto result = *this;
  for (int i = 0; i <= letters_count_; ++i) {
    result[i] = impossible_length_;
  }
  for (size_t i = 0; i <= letters_count_; ++i) {
    for (size_t j = 0; j <= i; ++j) {
      result[i] = std::min(result[i], (*this)[j] + other_automate[i - j]);
    }
  }

  return result;
}

const State State::operator^(size_t power) {
  auto result = *this;
  auto current_regular = *this;

  for (int i = 0; i < power; ++i) {
    current_regular = current_regular * *this;

    result = result + current_regular;
  }

  result[0] = 0;

  return result;
}
