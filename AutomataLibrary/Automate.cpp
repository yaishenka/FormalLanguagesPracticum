#include "Automate.hpp"
#include <stack>

using namespace automate;

std::experimental::optional<size_t> Automate::GetShortestWord(const std::string& regexp, char letter_to_find, int max_letters) {
  auto final_state = ProcessRegexp(regexp, letter_to_find, max_letters);

  return final_state[max_letters];
}

State Automate::ProcessRegexp(const std::string& regexp,
                              char letter_to_find,
                              int max_letters) {
  std::stack<State> states;

  for (auto symbol : regexp) {
    switch(symbol) {
      case '+': {
        if (states.size() < 2) {
          throw IncorrectRegexp();
        }

        auto first = states.top();
        states.pop();
        auto second = states.top();
        states.pop();

        first = first + second;

        states.push(first);
        break;
      }
      case '.': {
        if (states.size() < 2) {
          throw IncorrectRegexp();
        }

        auto first = states.top();
        states.pop();
        auto second = states.top();
        states.pop();

        first = first * second;

        states.push(first);
        break;
      }
      case '*': {
        if (states.empty()) {
          throw IncorrectRegexp();
        }

        auto top = states.top();
        states.pop();

        states.push(top^max_letters);
        break;
      }
      case ' ': {
        break;
      }
      default: {
        states.push(State(symbol, letter_to_find, max_letters));
      }

    }
  }

  if (states.size() > 1 || states.empty()) {
    throw IncorrectRegexp();
  }

  return states.top();
}
