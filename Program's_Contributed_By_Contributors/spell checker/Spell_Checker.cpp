#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
    int frequency = 0;
    double probability = 0.0;
};

class Trie {
private:
    TrieNode* root = new TrieNode();
    int totalWords = 0;  // Total word count.

public:
    void insert(const string& word, int frequency) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
        current->frequency = frequency;
        totalWords += frequency;  // Increment the total word count.
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) return false;
            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    vector<string> suggestCorrections(string word, int maxDistance) {
        vector<string> suggestions;
        suggestCorrectionsHelper(root, word, "", maxDistance, suggestions);
        sortSuggestions(suggestions);  // Sort suggestions by probability.
        return getTopSuggestions(suggestions, 10);  // Return the top 10 suggestions.
    }

private:
    void suggestCorrectionsHelper(TrieNode* node, string& target, string current, int maxDistance, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            int distance = levenshteinDistance(current, target);
            double probability = (node->frequency / static_cast<double>(totalWords)) * (1.0 / (distance + 1));

            if (distance <= maxDistance) {
                suggestions.push_back(current);
            }
        }

        if (current.length() >= target.length() + maxDistance) {
            return;
        }

        vector<pair<char, TrieNode*>> sortedChildren(node->children.begin(), node->children.end());
        sort(sortedChildren.begin(), sortedChildren.end(),
            [](const pair<char, TrieNode*>& a, const pair<char, TrieNode*>& b) {
                return a.second->frequency > b.second->frequency;
            });

        for (const auto& kv : sortedChildren) {
            suggestCorrectionsHelper(kv.second, target, current + kv.first, maxDistance, suggestions);
        }
    }

    int levenshteinDistance(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
            }
        }
        return dp[m][n];
    }

    void sortSuggestions(vector<string>& suggestions) {
        sort(suggestions.begin(), suggestions.end(),
            [](const string& a, const string& b) {
                return a < b;
            });
    }

    vector<string> getTopSuggestions(const vector<string>& suggestions, int topCount) {
        vector<string> topSuggestions;
        for (int i = 0; i < min(topCount, static_cast<int>(suggestions.size())); ++i) {
            topSuggestions.push_back(suggestions[i]);
        }
        return topSuggestions;
    }
};

int main() {
    Trie dictionary; // Create a trie to store words

    // Open the file for reading
    ifstream inputFile("count_big.txt");

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Read words and frequencies from the file and insert them into the trie
    string word;
    int frequency;

    while (inputFile >> word >> frequency) {
        dictionary.insert(word, frequency);
    }

    // Close the file
    inputFile.close();

    while (true) {
        cout << "Enter a word (or close! to exit): ";
        string userInput;
        cin >> userInput;

        if (userInput == "close!") {
            break; // Exit the program if the user enters "!stop"
        }

        if (dictionary.search(userInput)) {
            cout << userInput << " is a valid word." << endl;
        } else {
            cout << userInput << " is not found in the dictionary. Suggestions:" << endl;
            vector<string> suggestions = dictionary.suggestCorrections(userInput, 2); // Adjust the maxEditDistance as needed.

            // Display only the top 10 suggestions
            int count = 0;
            for (auto suggestion : suggestions) {
                if (count >= 10) break;
                cout << suggestion << endl;
                count++;
            }
        }
    }

    return 0;
}
