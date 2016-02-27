#include <iostream>
#include <vector>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target);
        void print();
};

void Solution::print()
{
    using namespace std;
    int my_ints[] = {2,7,11,5};
    vector<int> integers(my_ints, my_ints + sizeof(my_ints) / sizeof(int) );
    vector<int> to_print(twoSum(integers, 9));
    for (vector<int>::iterator it = to_print.begin(); it != to_print.end(); ++it)
        cout << ' ' << *it;
    cout << '\n'<<endl;
}

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
    using namespace std;
    int size = nums.size();
    vector<int> indices(2);
    for(int i = 0; i<size; ++i)
    {
        for(int j = i; j<size; ++j)
        {
            if(nums.at(i) + nums.at(j) == target)
            {
                indices.at(0) = i;
                indices.at(1) = j;
            }
        }
    }
    return indices;
}

int main()
{
    Solution solution;
    solution.print();
    return 0;
}
