#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"

TEST(PowTEST, TwoFive) {
	Base* two = new Op(2);
	Base* five = new Op(5);
	Base* test = new Pow(two, five);
	EXPECT_EQ(test->evaluate(), 32);
}

TEST(PowTEST, ZeroFive) {
	Base* zero = new Op(0);
	Base* five = new Op(5);
	Base* test = new Pow(zero, five);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTEST, NegOneFour) {
	Base* negone = new Op(-1);
	Base* four = new Op(4);
	Base* test = new Pow(negone, four);
	EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTEST, PowStringify) {
	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* test = new Pow(one, two);
	EXPECT_EQ(test -> stringify(), "1.0 ** 2.0");
}


#endif //__POW_TEST_HPP__
