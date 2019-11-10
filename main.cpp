#include <iostream>
#include <string>
#include <stack>
#include "AutomataLibrary/Automate.cpp"

class Solver {
 public:
  void operator()() {
    std::string regexp;
    std::getline(std::cin, regexp);

    char letter_to_collect;
    std::cin >> letter_to_collect;

    int max_letters;
    std::cin >> max_letters;

    Automate automate;

    try {
      size_t answer = automate.GetShortestWord(regexp, letter_to_collect, max_letters).value_or(0);

      if (answer == State::impossible_length_) {
        std::cout << "INF";
      } else {
        std::cout << answer;
      }
    } catch(automate::NotCompatibleRegexps& exception) {
      std::cout << "Trying to operate on different states";
    } catch (automate::IncorrectRegexp& exception) {
      std::cout << "Incorrect regexp";
    }
  }
};

int main() {
  Solver solver;
  solver();
}