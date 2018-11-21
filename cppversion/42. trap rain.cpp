#include <iostream>
#include <vector>

int trapRain(std::vector<int> &height)
{
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--)
        {
            max_left = std::max(max_left, height[j]);
        }
        for (int k = i; k < height.size(); k++)
        {
            max_right = std::max(max_right, height[k]);
        }
        ans += std::min(max_left, max_right) - height[i];
    }
    return ans;
}
int trapRain2(std::vector<int> &height)
{
    if (height.size() == 0)
        return 0;
    int n = height.size();
    std::vector<int> left(n);
    std::vector<int> right(n);
    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = std::max(left[i - 1], height[i]);
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = std::max(right[i + 1], height[i]);
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
        ans += std::min(left[i], right[i]) - height[i];
    return ans;
}
int main()
{
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trapRain2(height) << std::endl;
    std::cin.get();
}