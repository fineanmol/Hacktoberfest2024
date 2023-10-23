#ifndef _HUFFMAN_HPP_
#define _HUFFMAN_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
class node
{
public:
    string code;
    char c; // character
    int freq;
    node *left, *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};
class Huffman
{
    vector<node *> vec;
    fstream istream, ostream;
    string inFileName, outFileName;
    node *root = NULL;
    // creating this for definig userdefined comparator which will be used in Max heap
    class Comp
    {
    public:
        bool operator()(node *a, node *b)
        {
            return (a->freq > b->freq);
        }
    };
    priority_queue<node *, vector<node *>, Comp> pq;
    void createArr();

    // Traversing the constructed tree to generate huffman codes of each present character
    void traverse(node *, string);

    // Function to convert binary string to its equivalent decimal value
    int binToDec(string);

    void inorder(node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->c;
            inorder(root->right);
        }
    }

    // Function to convert a decimal number to its equivalent binary string
    string decToBin(int);

    // Reconstructing the Huffman tree while Decoding the file
    void buildTree(char, string &);

    // Creating Min Heap of Nodes by frequency of characters in the input file
    void createMinHeap();

    // Constructing the Huffman tree
    void createTree();

    // Generating Huffman codes
    void createCodes();

    // Saving Huffman Encoded File
    void saveEncodedFile();

    // Saving Decoded File to obtain the original File
    void saveDecodedFile();

    // Reading the file to reconstruct the Huffman tree
    void getTree();

public:
    Huffman(string inFileName, string outFileName)
    {
        this->inFileName = inFileName;
        this->outFileName = outFileName;
        createArr();
    }

    void compress();
    // Decrompressing input file
    void decompress();
};

#endif
