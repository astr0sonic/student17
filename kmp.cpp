#include "kmp.h"

std::vector<int> findPrefix(const std::string& pattern) {
    int length_pat = pattern.size();
    std::vector<int> prefix(length_pat, 0);
    
    int k = 0;
    for (int i = 1; i < length_pat; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            ++k;
        }
        prefix[i] = k;
    }
    return prefix;
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    int length_text = text.size();
    int length_pat = pattern.size();
    
    std::vector<int> prefix = findPrefix(pattern);
    std::vector<int> result;
    int k = 0;
    for (int i = 0; i < length_text; ++i) {
        while (k > 0 && pattern[k] != text[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == text[i]) {
            ++k;
        }
        if (k == length_pat) {
            result.push_back(i - length_pat + 1);
            k = prefix[k - 1];
        }
    }
    return result;
}


std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int>result = KMP(text, my_template);
    return result;
}
