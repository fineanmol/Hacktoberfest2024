#include "Huffman.hpp"

void Huffman::createArr()
{
    for (int i = 0; i < 128; i++)
    {
        node *a = new node();
        a->c = i;
        a->freq = 0;
        vec.push_back(a);
    }
}

// Traversing the constructed tree to generate huffman codes of each present character
void Huffman::traverse(node *n, string s)
{
    if (n->left == NULL && n->right == NULL)
    {
        n->code = s;
        return;
    }
    if (n->left != NULL)
    {
        traverse(n->left, s + "0");
    }
    if (n->right != NULL)
    {
        traverse(n->right, s + '1');
    }
}

// Function to convert binary string to its equivalent decimal value
int Huffman::binToDec(string s)
{
    int ans = 0;
    for (auto i : s)
    {
        ans = ans * 2 + i - '0';
    }
    return ans;
}

// Creating Min Heap of Nodes by frequency of characters in the input file
void Huffman::createMinHeap()
{
    char c;
    istream.open(inFileName, ios::in);

    while (istream.get(c))
    {
        vec[c]->freq++;
    }
    istream.close();
    for (auto i : vec)
    {
        if (i->freq > 0)
        {
            pq.push(i);
        }
    }
}

// Constructing the Huffman tree
void Huffman::createTree()
{
    node *l = NULL, *r = NULL;
    priority_queue<node *, vector<node *>, Comp> temp(pq);

    while (temp.size() != 1)
    {
        l = temp.top();
        temp.pop();

        r = temp.top();
        temp.pop();
        root = new node();
        root->freq = l->freq + r->freq;
        root->left = l;
        root->right = r;

        temp.push(root);
    }
    // here at last ,only one element will be left in the temp,which will be root of huffman tree
    // and stored in root variable of Huffman class
    priority_queue<node *, vector<node *>, Comp> temp1(pq);
    node *u = NULL;
    while (!temp1.empty())
    {
        temp1.pop();
    }
}

// Generating Huffman codes(just to initialise the traverse func)
void Huffman::createCodes()
{
    traverse(root, "");
}

// Saving Huffman Encoded File
void Huffman::saveEncodedFile()
{
    istream.open(inFileName, ios::in);
    ostream.open(outFileName, ios::out | ios::binary);
    string in = "";
    string s = "";
    char id;

    // Saving the meta data (huffman tree)
    in += (char)pq.size();

    priority_queue<node *, vector<node *>, Comp> tempPQ(pq);
    while (!tempPQ.empty())
    {
        node *curr = tempPQ.top();
        in += curr->c;
        // Saving 16 decimal values representing code of curr->data
        s.assign(127 - curr->code.length(), '0');
        s += '1';
        s += curr->code;
        // Saving decimal values of every 8-bit binary code
        in += (char)binToDec(s.substr(0, 8));
        for (int i = 0; i < 15; i++)
        {
            s = s.substr(8);
            in += (char)binToDec(s.substr(0, 8));
        }
        tempPQ.pop();
    }
    s.clear();

    // Saving codes of every charachter appearing in the input file
    istream.get(id);
    while (!istream.eof())
    {
        s += vec[id]->code;
        // Saving decimal values of every 8-bit binary code
        while (s.length() > 8)
        {
            in += (char)binToDec(s.substr(0, 8));
            s = s.substr(8);
        }
        istream.get(id);
    }

    // Finally if bits remaining are less than 8, append 0's
    int count = 8 - s.length();
    if (s.length() < 8)
    {
        s.append(count, '0');
    }
    in += (char)binToDec(s);
    // append count of appended 0's
    in += (char)count;

    // write the in string to the output file
    ostream.write(in.c_str(), in.size());
    istream.close();
    ostream.close();
}

// Function to convert a decimal number to its equivalent binary string
string Huffman::decToBin(int inNum)
{
    string temp = "", res = "";
    while (inNum > 0)
    {
        temp += (inNum % 2 + '0');
        inNum /= 2;
    }
    res.append(8 - temp.length(), '0');
    for (int i = temp.length() - 1; i >= 0; i--)
    {
        res += temp[i];
    }
    return res;
}

// Reconstructing the Huffman tree while Decoding the file
void Huffman::buildTree(char a_code, string &path)
{
    node *curr = root;

    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '0')
        {
            if (curr->left == NULL)
            {
                curr->left = new node();
            }
            curr = curr->left;
        }
        else if (path[i] == '1')
        {
            if (curr->right == NULL)
            {
                curr->right = new node();
            }
            curr = curr->right;
        }
    }
    curr->c = a_code;
}
// Saving Decoded File to obtain the original File
void Huffman::saveDecodedFile()
{
    istream.open(inFileName, ios::in | ios::binary);
    ostream.open(outFileName, ios::out);
    unsigned char size;
    istream.read(reinterpret_cast<char *>(&size), 1);
    // Reading count at the end of the file which is number of bits appended to make final value 8-bit
    istream.seekg(-1, ios::end);
    char count0;
    istream.read(&count0, 1);
    // Ignoring the meta data (huffman tree) (1 + 17 * size) and reading remaining file
    istream.seekg(1 + 17 * size, ios::beg);

    vector<unsigned char> text;
    unsigned char textseg;
    istream.read(reinterpret_cast<char *>(&textseg), 1);
    while (!istream.eof())
    {
        text.push_back(textseg);
        istream.read(reinterpret_cast<char *>(&textseg), 1);
    }

    node *curr = root;
    string path;
    for (int i = 0; i < text.size() - 1; i++)
    {
        // Converting decimal number to its equivalent 8-bit binary code
        path = decToBin(text[i]);
        if (i == text.size() - 2)
        {
            path = path.substr(0, 8 - count0);
        }
        // Traversing huffman tree and appending resultant data to the file
        for (int j = 0; j < path.size(); j++)
        {
            if (path[j] == '0')
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }

            if (curr->left == NULL && curr->right == NULL)
            {
                ostream.put(curr->c);
                curr = root;
            }
        }
    }
    istream.close();
    ostream.close();
}

void Huffman::compress()
{
    createMinHeap();
    createTree();
    createCodes();
    saveEncodedFile();
}

// Reading the file to reconstruct the Huffman tree
void Huffman::getTree()
{
    istream.open(inFileName, ios::in | ios::binary);
    // Reading size of MinHeap
    unsigned char size;
    istream.read(reinterpret_cast<char *>(&size), 1);
    root = new node();
    // next size * (1 + 16) characters contain (char)data and (string)code[in decimal]
    for (int i = 0; i < size; i++)
    {
        char aCode;
        unsigned char hCodeC[16];
        istream.read(&aCode, 1);
        istream.read(reinterpret_cast<char *>(hCodeC), 16);
        // converting decimal characters into their binary equivalent to obtain code
        string hCodeStr = "";
        for (int i = 0; i < 16; i++)
        {
            hCodeStr += decToBin(hCodeC[i]);
        }
        // Removing padding by ignoring first (127 - curr->code.length()) '0's and next '1' character
        int j = 0;
        while (hCodeStr[j] == '0')
        {
            j++;
        }
        hCodeStr = hCodeStr.substr(j + 1);
        // Adding node with aCode data and hCodeStr string to the huffman tree
        buildTree(aCode, hCodeStr);
    }
    istream.close();
}
void Huffman::decompress()
{
    getTree();
    saveDecodedFile();
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "File not detected! ";
        return 0;
    }
    cout << argv[1] << endl
         << argv[2] << endl;
    Huffman h(argv[1], argv[2]);
    int i{};
    cout << "Select the option 1.Compress  2.Decompress\n";
    cin >> i;
    if (i == 1)
    {
        h.compress();
        cout << "Compressed Successfully!";
    }

    if (i == 2)
    {
        h.decompress();
        cout << "Decompressed Successfully" << endl;
    }
    return 0;
}