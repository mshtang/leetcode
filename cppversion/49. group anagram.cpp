#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::multiset<std::string>> mp;
    for (auto s : strs)
    {
        std::string t = s;
        std::sort(t.begin(), t.end());
        mp[t].insert(s);
    }

    std::vector<std::vector<std::string>> res;
    for (auto m : mp)
    {
        std::vector<std::string> anagram(m.second.begin(), m.second.end());
        res.push_back(anagram);
    }
    return res;
}

int main()
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> res;
    res = groupAnagram(strs);
    for (auto str : res)
    {
        for (auto i : str)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}