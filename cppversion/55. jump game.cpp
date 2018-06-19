#include <iostream>
#include <vector>

enum Index
{
    GOOD,
    BAD,
    UNKNOWN

};
class JumpGame
{
  public:
    inline bool canJump(std::vector<int> nums)
    {
        return canJumpFromPosition(0, nums);
    }

    inline bool canJump_DP(std::vector<int> nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            index.push_back(Index::UNKNOWN);
        }
        index[nums.size() - 1] = Index::GOOD;
        return canJumpFromPosition_DP(0, nums);
    }

  private:
    bool canJumpFromPosition(int pos, std::vector<int> nums);
    bool canJumpFromPosition_DP(int pos, std::vector<int> nums);
    std::vector<Index> index;
};

bool JumpGame::canJumpFromPosition(int pos, std::vector<int> nums)
{
    if (pos == nums.size() - 1)
        return true;

    int furthestJump = std::min(pos + nums[pos], (int)(nums.size() - 1));
    for (int nextpos = furthestJump; nextpos > pos; --nextpos)
    {
        if (canJumpFromPosition(nextpos, nums))
            return true;
    }
    return false;
}

bool JumpGame::canJumpFromPosition_DP(int pos, std::vector<int> nums)
{
    if (index[pos] != Index::UNKNOWN)
        return index[pos] == Index::GOOD ? true : false;
    int furthestJump = std::min(pos + nums[pos], (int)(nums.size() - 1));
    for (int nextpos = pos + 1; nextpos <= furthestJump; ++nextpos)
    {
        if (canJumpFromPosition_DP(nextpos, nums))
        {
            index[pos] = Index::GOOD;
            return true;
        }
    }
    index[pos] = Index::BAD;
    return false;
}

int main()
{
    JumpGame solution;
    std::vector<int> false_nums{5, 4, 3, 2, 1, 0, 0};
    std::vector<int> true_nums{1, 5, 2, 1, 0, 2, 0};
    std::cout << "false nums: " << solution.canJump(false_nums) << std::endl;
    std::cout << "true nums: " << solution.canJump(true_nums) << std::endl;
    std::cout << "false dp: " << solution.canJump_DP(false_nums) << std::endl;
    std::cout << "true dp: " << solution.canJump_DP(true_nums) << std::endl;
    std::cin.get();
}
