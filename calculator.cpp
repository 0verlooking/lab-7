#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

std::pair<std::string, int> findShortestWord(const std::string& str) {
    std::map<std::string, int> wordCount;
    std::string word, shortestWord;
    std::istringstream iss(str);

    while(iss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end()); // Remove punctuation
        wordCount[word]++;

        if (shortestWord.empty() || word.length() < shortestWord.length()) {
            shortestWord = word;
        }
    }

    return std::make_pair(shortestWord, wordCount[shortestWord]);
}

int main() {
    std::string text;
    std::cout << "Enter the text: " << std::endl;
    getline(std::cin, text);

    auto result = findShortestWord(text);
    std::cout << "The shortest word is: " << result.first << std::endl;
    std::cout << "It appears " << result.second << " times." << std::endl;

    return 0;
}