//Copyright 2017 Chuan Xing Zheng czheng78@bu.edu
//U32336445
//HWK3

#include <string>
#include <vector>
using namespace std;

// Define type string as BigInt
typedef string BigInt;

// The multiply function
BigInt multiply_int(const BigInt &a, const BigInt &b) {

  int a_size = a.size();
  int b_size = b.size();

  vector<int> result(a_size + b_size, 0);

  int i_a1 = 0;
  int i_b1 = 0;

  for (int i = a_size - 1; i >= 0; i--) {
    int carry = 0;
    int a_size = a[i] - '0';

    i_b1 = 0;

    for (int j = b_size - 1; j >= 0; j--) {
      int b_size = b[j] - '0';

      int sum = a_size * b_size + result[i_a1 + i_b1] + carry;

      carry = sum / 10;

      result[i_a1 + i_b1] = sum % 10;

      i_b1++;
    }

    if (carry > 0)
      result [i_a1 + i_b1] += carry;

    i_a1++;
  }

  int x = result.size() - 1;
  while (x >= 0 && result[x] == 0)
    x--;

  if (x == -1)
    return "0";

  string c = "";

  while (x >= 0)
    c += to_string(result[x--]);

  return c;
}
