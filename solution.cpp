#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol1055;
using namespace std;

/*takeaways
  - use abbaba as an example
    - when you are at this location ab[b] and look back
      at the chars that come before it, which is ab,
      you will find two substring a and b. So by scanning
      in one more 'b', there will be a repeat for [b]
      substring so dp[3][2] = 1, 3 means you are at
      this location ab[b], and the length of the
      substring "b" is 1
    - we scan in another a -> abb[a]
      - we found a repeat for a, so dp[4][1] = 1
    - we scan in another b -> abba[b]
      - here is the key
      - the string that comes before is abba
      - visit it one chat at a time
        - [a]bba -> [a] != b -> move on
        - a[b]ba -> [b] == b
          - so how do we set up the dp[5][2]?
          - we look at dp[5-1][2-1] which means
            when we scanned in last char, which
            was 'a', row index 5-1, did we find
            a repeat at the char position before
            the one we are comparing right now?
          - we found dp[5-1][2-1] is 1, so yes
            the substring "a" is repeated, so
            we now repeat another "b", so together
            we have a repeat for "ab", which has
            a length 2, so dp[5][2] = dp[4][1]+1

  -
      a b b a b a
    a 0 0 0 0 0 0
    b 0 0 0 0 0 0
       \
    b 0 1 0 0 0 0 scan in a 'b'; found a repeat for substring [b]
    a 1 0 0 0 0 0 scan in a 'a'; found a repeat for substring [a]
       \
    b 0 2 1 0 0 0 scan in a 'b'; found a repeat for substring [ab]
           \
    a 1 0 0 2 0 0 scan in a 'a'; found a repeat for substring [a]
                                 found a repeat for substring [ba]
                                 the value in dp is the length
                                 not the occurrence of the substring
*/

int Solution::findLongest(string s)
{
  const int n = s.size();
  auto result = 0;
  /*change it to 1-based */
  auto dp = vector<vector<int>>(n + 1, vector<int>(n + 1));

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j < i; j++)
    {
      /* compare char i to char j */
      if (s[i - 1] == s[j - 1])
      {
        /*grow the substring if a repeat in the previous
          char in the previous scan is also a repeat
        */
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      result = max(result, dp[i][j]);
    }
  return result;
}