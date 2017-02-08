#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;

		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i+1; j < nums.size(); j++)
			{
				if ((nums[i] + nums[j]) == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
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