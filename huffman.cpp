#include "huffman.h"


void encodedStr(node* root, string str, map<char, string>& huffmanCode)
{
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        huffmanCode[root->info] = (!str.empty()) ? str : "1";
    }
    encodedStr(root->left, str + "0", huffmanCode);
    encodedStr(root->right, str + "1", huffmanCode);
}

string encode(const string& text) {
    string encoded = "";
    priority_queue<node*, vector<node*>, comp> pq;

    map<char, int> mp;
    for (char c : text)
        mp[c] += 1;

    for (auto i : mp)
        pq.push(new node{ i.first, i.second, NULL, NULL });

    while (pq.size() != 1) {
        node* left = pq.top(); pq.pop();
        node* right = pq.top(); pq.pop();
        pq.push(new node{ '\0', left->freq + right->freq, left, right });
    }
    node* root = pq.top();

    map<char, string> huffmanCode;
    encodedStr(root, encoded, huffmanCode);

    for (char ch : text)
        encoded += huffmanCode[ch];

    return encoded;
}

string decode(const string& encoded, map<char, string>& codes) {
    string decoded = "";
    map<string, char> newcodes;
    for (auto i : codes)
        newcodes[i.second] = i.first;
    string temp = "";
    for (char ch : encoded) {
        temp += ch;
        if (newcodes.find(temp) != newcodes.end())
        {
            decoded += newcodes[temp];
            temp.clear();
        }
    }
    return decoded;
}
