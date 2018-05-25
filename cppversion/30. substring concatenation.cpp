#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    std::unordered_map<std::string, int> counts;
    for (std::string word : words)
        counts[word]++;
    int len_str = s.length(), num_of_words = words.size(), len_of_each_word = words[0].length();
    std::vector<int> indices;
    for (int i = 0; i < len_str - num_of_words * len_of_each_word + 1; i++)
    {
        std::unordered_map<std::string, int> seen;
        int j = 0;
        for (; j < num_of_words; j++)
        {
            std::string word = s.substr(i + j * len_of_each_word, len_of_each_word);
            if (counts.find(word) != counts.end()) // if word is found
            {
                seen[word]++;
                if (seen[word] > counts[word])
                    break;
            }
            else
                break;
        }
        if (j == num_of_words)
            indices.push_back(i);
    }
    return indices;
}

int main()
{
    std::string input_str = "barfoothefoobarman";
    std::vector<std::string> words = {"foo", "bar"};
    std::vector<int> indices;
    indices = findSubstring(input_str, words);
    for (int index : indices)
        std::cout << index << " ";
    std::cin.get();
}