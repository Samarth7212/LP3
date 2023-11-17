
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

class HuffmanEncoding
{
public:
    class Node
    {
    public:
        char data;
        int freq;
        Node *left, *right;

        Node(char data, int freq)
        {
            this->data = data;
            this->freq = freq;
            left = right = nullptr;
        }
    };
    struct CMP
    {
        bool operator()(Node *x, Node *y) { return (x->freq > y->freq); }
    };

private:
    priority_queue<Node *, vector<Node *>, CMP> minHeap;

public:
    HuffmanEncoding()
    {
    }
    void pushData(unordered_map<char, int> &mp)
    {
        for (auto &x : mp)
        {
            Node *tmp = new Node(x.first, x.second);
            this->minHeap.push(tmp);
        }
        generateHuffmanCode();
        printCodes(minHeap.top(), "");
    }

    void printCodes(Node *x, string str)
    {
        if (x == nullptr)
            return;
        if (x->data != 'X')
            cout << x->data << " : " << str << endl;
        printCodes(x->left, str + "0");
        printCodes(x->right, str + "1");
    }

    void generateHuffmanCode()
    {
        Node *left = nullptr, *right = nullptr, *tmp = nullptr;

        while (minHeap.size() != 1)
        {
            left = minHeap.top();
            minHeap.pop();
            right = minHeap.top();
            minHeap.pop();

            tmp = new Node('X', left->freq + right->freq);
            tmp->left = left;
            tmp->right = right;
            minHeap.push(tmp);
        }

        cout << "TOP: " << minHeap.top()->data << endl;
    }
};

int main()
{
    unordered_map<char, int> mp;
    string text = "THIS IS A RANDOM TEXT";
    for (char &x : text)
    {
        if (x == ' ')
            mp['_']++;
        else
            mp[x]++;
    }

    cout << "Frequencies: \n";
    for (auto &x : mp)
    {
        cout << x.first << " : " << x.second << endl;
    }

    cout << endl
         << endl;
    HuffmanEncoding huff = HuffmanEncoding();
    huff.pushData(mp);
    return 0;
}