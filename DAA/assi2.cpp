// Write a program to implement Huffman Encoding using a greedy strategy.

#include <iostream>
#include <map>
#include <vector>
#include <queue>

class HuffmanNode
{
public:
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    }

    bool operator>(const HuffmanNode &node) const
    {
        return frequency > node.frequency;
    }
};

std::map<char, std::string> buildHuffmanCodes(const std::string &text)
{
    // Calculate character frequencies
    std::map<char, int> charFrequencies;
    for (char c : text)
    {
        charFrequencies[c]++;
    }

    // Create a priority queue to store nodes
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, std::greater<HuffmanNode>> priorityQueue;
    for (const auto &entry : charFrequencies)
    {
        priorityQueue.push(HuffmanNode(entry.first, entry.second));
    }

    // Build the Huffman tree
    while (priorityQueue.size() > 1)
    {
        HuffmanNode *left = new HuffmanNode(priorityQueue.top().data, priorityQueue.top().frequency);
        priorityQueue.pop();
        HuffmanNode *right = new HuffmanNode(priorityQueue.top().data, priorityQueue.top().frequency);
        priorityQueue.pop();
        HuffmanNode *combined = new HuffmanNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        priorityQueue.push(*combined);
    }

    // Build Huffman codes
    HuffmanNode *root = new HuffmanNode(priorityQueue.top().data, priorityQueue.top().frequency);
    std::map<char, std::string> huffmanCodes;
    buildCodes(root, "", huffmanCodes);

    return huffmanCodes;
}

void buildCodes(HuffmanNode *node, std::string code, std::map<char, std::string> &huffmanCodes)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        huffmanCodes[node->data] = code;
    }

    buildCodes(node->left, code + "0", huffmanCodes);
    buildCodes(node->right, code + "1", huffmanCodes);
}

int main()
{
    std::string text = "this is an example for huffman encoding";

    std::map<char, std::string> huffmanCodes = buildHuffmanCodes(text);

    std::cout << "Huffman Codes:" << std::endl;
    for (const auto &entry : huffmanCodes)
    {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }

    return 0;
}
