[![Build Status](https://travis-ci.com/yaishenka/FormalLanguagesPracticum.svg?branch=master)](https://travis-ci.com/yaishenka/FormalLanguagesPracticum) [![codecov](https://codecov.io/gh/yaishenka/FormalLanguagesPracticum/branch/master/graph/badge.svg)](https://codecov.io/gh/yaishenka/FormalLanguagesPracticum)
# FormalLanguagesPracticum

Short discription: algorithm takes regexp in reverse polish notation and print len of word a: len(a) - min and a contains k letters x

State[i] - len(a), where a contains i letters of x 

Answer - End state[k]

Note: r^* = r^k = r + rr + rrr + ... + r^k
