#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> tmp;

		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i+1; j < nums.size(); j++)
			{
				if ((nums[i] + nums[j]) == target)
				{
					tmp.push_back(i);
					tmp.push_back(j);
					return tmp;
				}
			}
		}
		return tmp;
	}
};

int main(int argc, const char* argv[])
{
	Solution s;
	int myints[] = {3, 2, 4};
	std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

	vector<int> answer = s.twoSum(nums, 6);

	for (size_t i = 0; i < answer.size(); i++)
	{
		cout << answer[i] <<endl;
	}
}