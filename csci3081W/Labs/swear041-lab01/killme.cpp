#include <iostream>
using namespace std;

int main() {
   int stop;
   int result;
   int a;
   int b;

   cin >> stop;
   result = 0;

   for (a = 0; a < 2; ++a) {
      cout << a << ": ";
      for (b = 0; b < 4; ++b) {
         result += a + b;
         if (result > stop) {
            cout << "_ ";
            continue;
         }
         cout << result << ",";
      }
      cout << endl;
   }

   return 0;
}