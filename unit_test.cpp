#include "gtest/gtest.h"
#include "iterator.hpp"
#include "op.hpp"
#include "add.hpp"
#include "decorator.hpp"
#include "mult.hpp"
#include "Floor.hpp"
int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(BinaryIteratorTest, TestAddBinary) {
	Base* seven = new Op(7);
	Base* eight = new Op(8);
	Base* add = new Add(seven, eight);
	EXPECT_EQ(add->create_iterator()->current(), seven);
	EXPECT_EQ(add->create_iterator()->current(), eight);
}	

TEST(UnaryIteratortest, TestFloorBinary) {
	Base* two = new Op(2.5);
	Base* three = new Op(3);
	Base* mult = new Mult(two, three);
	Decorator* floor = new Floor(mult);
	EXPECT_EQ(floor->create_iterator()->current(), mult);
}




