/** @author yaishenka
    @date 2019-11-10 */
#include "AutomataLibrary/Automate.cpp"
#include <gtest/gtest.h>

TEST(TEST_FROM_PASHA, FIRST) {
  std::string regexp = "ab + c.aba. * .bac. + . + *";
  automate::Automate automate;
  size_t answer = automate.GetShortestWord(regexp, 'b', 2).value();
  EXPECT_EQ(answer, 4);
}

TEST(TEST_FROM_PASHA, SECOND) {
  std::string regexp = "acb..bab.c. * .ab.ba. + . + *a.";
  automate::Automate automate;
  size_t answer = automate.GetShortestWord(regexp, 'b', 3).value();
  EXPECT_EQ(answer, 7);
}

TEST(EXCEPTIONS, STACK_SIZE) {
  std::string regexp = "aa.b";
  automate::Automate automate;
  ASSERT_ANY_THROW(automate.GetShortestWord(regexp, 'a', 1));
}

TEST(EXCEPTIONS, MISSING_OPERANDS_CLOSURE) {
  std::string regexp = "*a";
  automate::Automate automate;
  ASSERT_ANY_THROW(automate.GetShortestWord(regexp, 'a', 1));
}

TEST(EXCEPTIONS, MISSING_OPERANDS_DISJUNCTION) {
  std::string regexp = "+a";
  automate::Automate automate;
  ASSERT_ANY_THROW(automate.GetShortestWord(regexp, 'a', 1));
}

TEST(EXCEPTIONS, MISSING_OPERANDS_CONCATENATION) {
  std::string regexp = ".a";
  automate::Automate automate;
  ASSERT_ANY_THROW(automate.GetShortestWord(regexp, 'a', 1));
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
