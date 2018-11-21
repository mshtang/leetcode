from collections import Counter


def findSubstring(s, words):
    counts = Counter()
    for word in words:
        counts[word] += 1
    len_str = len(s)
    num_of_words = len(words)
    len_of_each_word = len(words[0])
    indices = []
    for i in range(len_str - num_of_words * len_of_each_word + 1):
        seen = Counter()
        for j in range(num_of_words):
            word = s[i + j * len_of_each_word:i + (j + 1) * len_of_each_word]
            if word in words:
                seen[word] += 1
                if seen[word] > counts[word]:
                    break
            else:
                break
        if (j + 1) == num_of_words:
            indices.append(i)
    return indices


if __name__ == '__main__':
    print(findSubstring('barfoothefoobarman', ['foo', 'bar']))
