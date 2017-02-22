#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		std::map<char, int> m;
		int maxlen = 0;
		int start = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (m.count(s[i]) != 0)
			{
				maxlen = max(maxlen, int(i - start));
				start = max(start, int(m[s[i]] + 1));
			}
			
			m[s[i]] = i;
		}
		maxlen = std::max(maxlen, int(s.size() - start));
		return maxlen;
	}
};


int main(int argc , const char *argv[])
{
	Solution s;

	cout << s.lengthOfLongestSubstring("abcdfegabcd") <<endl;

	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

	cout << s.lengthOfLongestSubstring("bbbb") << endl;

	cout << s.lengthOfLongestSubstring("abbac") << endl;

	return 0;
}