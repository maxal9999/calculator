/**
 * \file
 * \brief Unit tests of the project
 * \author Maksimovskiy A.S.
 */


#include "calculator.hpp"

#include <fstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestCalculator

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestCalculator) // Начало набора тестов


BOOST_AUTO_TEST_CASE(TestCalculatorSimple)
{
   std::stringstream input_expression;
   input_expression << "(1+ 2) * 3 - 98 * 76" << std::endl;
   auto result = impl::Calculator(input_expression).Execute();
   BOOST_CHECK_EQUAL(result, -7439);
}

BOOST_AUTO_TEST_CASE(TestCalculatorWithInnerBrackets)
{
   std::stringstream input_expression;
   input_expression << "3+ ((1 + 2) * 3 + (56 - 76)) - 98 * 76" << std::endl;
   auto result = impl::Calculator(input_expression).Execute();
   BOOST_CHECK_EQUAL(result, -7456);
}

BOOST_AUTO_TEST_CASE(TestCalculatorWithLargeTabs)
{
   std::stringstream input_expression;
   input_expression << "(           3    +    4    )   *  6    - 12" << std::endl;
   auto result = impl::Calculator(input_expression).Execute();
   BOOST_CHECK_EQUAL(result, 30);
}

BOOST_AUTO_TEST_CASE(TestCalculatorFromFile)
{
   // Create file
   auto file_path = "TestCalculatorFromFile.txt";
   std::ofstream fout(file_path);
   fout << "3+ ((1 + 2) * 3 + (56 - 76)) - 98 * 76";
   fout.close();

   std::ifstream fin(file_path);
   auto result = impl::Calculator(fin).Execute();
   BOOST_CHECK_EQUAL(result, -7456);

   remove(file_path);
}

BOOST_AUTO_TEST_SUITE_END() // Конец набора тестов
