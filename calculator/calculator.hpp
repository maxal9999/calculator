#pragma once

/**
 * \file
 * \brief Calculator implementation
 * \author Maksimovskiy A.S.
 */

#include <iostream>


namespace impl
{

class Calculator
{
public:
   Calculator(std::istream& input_stream);

   double Execute();

private:
   std::istream& mInput;

   double Coefficient();

   double FindBrackets();

   char NextChar();

   double Number();
};

}
