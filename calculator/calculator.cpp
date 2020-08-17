/**
 * \file
 * \brief Calculator implementation
 * \author Maksimovskiy A.S.
 */

#include "calculator.hpp"

namespace impl
{

Calculator::Calculator(std::istream& input_stream)
   : mInput(input_stream)
{
}

char Calculator::NextChar()
{
   char next_char = ' ';
   while (mInput.get(next_char) && next_char == ' ')
      continue;

   return next_char;
}

double Calculator::Number()
{
   double result = 0.0;
   while (true)
   {
      auto next_char = NextChar();
      if (next_char >= '0' && next_char <= '9')
         result = result * 10 + (next_char - '0');
      else
      {
         mInput.putback(next_char);
         return result;
      }
   }
}

double Calculator::FindBrackets()
{
   auto next_char = NextChar();
   if (next_char == '(')
   {
      double result = Execute();
      mInput.get();
      return result;
   }
   else
   {
      mInput.putback(next_char);
      return Number();
   }
}

double Calculator::Coefficient()
{
   double result = FindBrackets();
   while (true)
   {
      auto next_char = NextChar();
      switch (next_char)
      {
      case '*':
         result *= FindBrackets();
         break;
      case '/':
         result /= FindBrackets();
         break;
      default:
         mInput.putback(next_char);
         return result;
      }
   }
}

double Calculator::Execute()
{
   double result = Coefficient();
   while (true)
   {
      auto next_char = NextChar();
      switch (next_char)
      {
      case '+':
         result += Coefficient();
         break;
      case '-':
         result -= Coefficient();
         break;
      default:
         mInput.putback(next_char);
         return result;
      }
   }
}

}
