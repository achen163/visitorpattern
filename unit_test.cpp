#include "gtest/gtest.h"
#include "iterator.hpp"
#include "op.hpp"
#include "add.hpp"
#include "decorator.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "Floor.hpp"
#include "paren.hpp"
#include "visitor.hpp"
int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(BinaryIteratorTest, TestAddBinary) {
	Base* seven = new Op(7);
	Base* eight = new Op(8);
	Base* add = new Add(seven, eight);
	Iterator* test = add->create_iterator();
	EXPECT_EQ(test->current(), seven);

	test->next();
	EXPECT_EQ(test->current(), eight);

	test->first();
	EXPECT_EQ(test->current(), seven);
	EXPECT_EQ(test->is_done(), false);

	test->next();
	test->next();
	EXPECT_EQ(test->is_done(), true);	
}	

TEST(UnaryIteratorTest, TestFloorUnary) {
	Base* two = new Op(2.5);
	Base* three = new Op(3);
	Base* mult = new Mult(two, three);
	Decorator* floor = new Floor(mult);
	Iterator* test2 = floor->create_iterator();
	EXPECT_EQ(test2->current(), mult);

	test2->next();
	EXPECT_EQ(test2->current(), nullptr);
	
	test2->first();
	EXPECT_EQ(test2->current(), mult);
	EXPECT_EQ(test2->is_done(), false);
	
	test2->next();
	EXPECT_EQ(test2->is_done(), true);
}

TEST(NullIteratorTest, TestOpNull) {
	Base* six = new Op(6);
	EXPECT_EQ(six->create_iterator()->current(), nullptr);
	EXPECT_EQ(six->create_iterator()->is_done(), true);
}

TEST(PreorderIteratorTest, TestExpressionPreorder) {
	Base* ten = new Op(10);

	
	Base* thirteen = new Op(13);
	Base* add2 = new Add(ten, thirteen);
	Base* sub = new Sub(add2, ten);
	Base* mult = new Mult(sub, thirteen);
	Base* paren = new Paren(mult); //dummy node
	Iterator* test = new PreorderIterator(paren); 
	
	test->first();

	EXPECT_EQ(test->current(), mult);
	test->next();
	EXPECT_EQ(test->current(), sub);
	EXPECT_EQ(test->is_done(), false);
	test->next();
	test->next();
	test->next();
	test->next();
	test->next();
	test->next();
	EXPECT_EQ(test->is_done(), true);	
}

TEST(VisitorCountTest, TestVisitor) {
	CountVisitor* visitor = new CountVisitor();

	Base* twenty = new Op(20);
	Base* sixteen = new Op(16);
	Base* sub2 = new Sub(twenty, sixteen);
	Base* mult2 = new Mult(sub2, twenty);
	Base* paren2 = new Paren(mult2); //dummy node

	Iterator* countTest = new PreorderIterator(paren2);
	countTest->first();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->mult_count(), 1);

	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->sub_count(), 1);

	countTest->next();
	countTest->current()->accept(visitor);
	countTest->next();
	countTest->current()->accept(visitor);
	countTest->next();
	countTest->current()->accept(visitor);
	
	EXPECT_EQ(visitor->op_count(), 3);

}	


