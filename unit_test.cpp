#include "gtest/gtest.h"
#include "iterator.hpp"
#include "op.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "decorator.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "Trunc.hpp"
#include "abs.hpp"
#include "Floor.hpp"
#include "paren.hpp"
#include "rand.hpp"
#include "ceil.hpp"
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

TEST(VisitorCountTest2, TestVisitor){
	CountVisitor* visitor = new CountVisitor();

	Base* two3 = new Op(2);
	Base* six3 = new Op(6);
	Base* add2 = new Add(two3, six3);
	Base* div2 = new Div(add2, two3);
	Base* pow = new Pow(two3,div2);
	Base* paren3 = new Paren(pow);	
	
	Iterator* countTest = new PreorderIterator(paren3);
	
	countTest->first();
	EXPECT_EQ(countTest->current(), pow);
	
	countTest->next();
	countTest->next();	
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->div_count(),1);
	
	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->add_count(),1);
	
	countTest->next();
	countTest->current()->accept(visitor);
	countTest->next();
	countTest->current()->accept(visitor);
	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->op_count(),3);
}

TEST(VisitorCountTest3, TestVisitor) {
	CountVisitor* visitor = new CountVisitor();

	Base* negTwo = new Op(-2.5);
	Base* posThree2 = new Op(3);
	Base* mult23 = new Mult(negTwo,posThree2);
	Base* abs2 = new Abs(mult23);
	Base* floor = new Floor(abs2);
	Base* trunc = new Trunc(floor);
	Base* paren4 = new Paren(trunc);
	Base* paren5 = new Paren(paren4);

	Iterator* countTest = new PreorderIterator(paren5);

	countTest->first();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->paren_count(), 1);

	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->trunc_count(),1);
	
	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->floor_count(),1);
	
	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->abs_count(),1);

}

TEST(VisitorCountTest4, TestVisitor) {
	CountVisitor* visitor = new CountVisitor();
	
	Base* random = new Rand();
	
	Base* ceil = new Ceil(random);
	Base* paren = new Paren(ceil); //dummynode
	Iterator* countTest = new PreorderIterator(paren);
	
	countTest->first();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->ceil_count(), 1);
	
	countTest->next();
	countTest->current()->accept(visitor);
	EXPECT_EQ(visitor->rand_count(), 1);
}
	
