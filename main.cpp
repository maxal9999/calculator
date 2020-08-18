#include "calculator/calculator.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <locale>


namespace
{

enum CalculatorMode
{
   MANUAL = 1,
   FROM_FILE
};

}

int main()
{
   // Local
   std::locale::global(std::locale(""));
   // Fast std::cin
   std::ios::sync_with_stdio(false);

   auto clear_all = []()
   {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#ifdef _WIN32
      system("cls");
#elif __linux__
      system("clear");
#endif
   };

   // Choose calculator mode
   bool no_mode = true;
   CalculatorMode mode = CalculatorMode::MANUAL;
   while (no_mode)
   {
      std::wcout << L"Выберите режим работы калькулятора: " << std::endl;
      std::wcout << L"1 - ввод арифметического выражения вручную" << std::endl;
      std::wcout << L"2 - чтение арифметического выражения из файла" << std::endl;

      int mode_int = 0;
      std::cin >> mode_int;
      clear_all();

      mode = static_cast< CalculatorMode >(mode_int);
      switch (mode)
      {
      case CalculatorMode::MANUAL:
      case CalculatorMode::FROM_FILE:
         no_mode = false;
         break;
      }
   }

   char d = 'y';

   auto manual_calculate = []()
   {
      std::wcout << L"Введите арифметическое выражение: " << std::endl;
      double result = impl::Calculator(std::cin).Execute();
      std::wcout << L"Результат: " << result << std::endl;
   };

   auto from_file_calculate = []()
   {
      std::wcout << L"Введите имя файла с арифметическим выражением: " << std::endl;
      std::string file_path;
      std::getline(std::cin, file_path);

      // Open file
      std::ifstream file_stream(file_path);
      if (file_stream.is_open())
      {
         double result = impl::Calculator(file_stream).Execute();
         std::wcout << L"Результат: " << result << std::endl;
      }
      else
         std::wcout << L"Не удалось открыть файл" << std::endl;
   };

   do
   {
      switch (mode)
      {
      case CalculatorMode::MANUAL:
         manual_calculate();
         break;
      case CalculatorMode::FROM_FILE:
         from_file_calculate();
         break;
      }

      std::wcout << L"Повторить? (y/n)" << std::endl;
      std::cin >> d;
      clear_all();
   }
   while (d == 'y');

   return 0;
}
