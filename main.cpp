#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1055;

/*
Example 1:
Input: “abcd”
Output: 0
Explanation: There is no repeating substring.
*/
tuple<string, int>
testFixture1()
{
  return make_tuple("abcd", 0);
}

/*
Example 2:
Input: “abbaba”
Output: 2
Explanation: The longest repeating substrings are “ab” and “ba”,
each of which occurs twice.
*/
tuple<string, int>
testFixture2()
{
  return make_tuple("abbaba", 2);
}

/*
Example 3:
Input: “aabcaabdaab”
Output: 3
Explanation: The longest repeating substring is “aab”, which occurs 3 times.
*/
tuple<string, int>
testFixture3()
{
  return make_tuple("aabcaabdaab", 3);
}

/*
Input: “aaaaa”
Output: 4
Explanation: The longest repeating substring is “aaaa”, which occurs twice.
*/
tuple<string, int>
testFixture4()
{
  return make_tuple("aaaaa", 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findLongest(get<0>(f));
  cout << "result: " << result << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findLongest(get<0>(f));
  cout << "result: " << result << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findLongest(get<0>(f));
  cout << "result: " << result << endl;
}

void test4()
{
  auto f = testFixture4();
  cout << "Test 4 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findLongest(get<0>(f));
  cout << "result: " << result << endl;
}

main()
{
  // test1();
  test2();
  // test3();
  // test4();
  return 0;
}