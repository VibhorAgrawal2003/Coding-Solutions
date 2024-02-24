#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct treenode{
    char name;
    double val;
    struct treenode* left;
    struct treenode* right;
} tn;

struct comparator{
    bool operator()(tn* A, tn* B){
        return A->val > B->val;
    }
};

void tree_traversal(tn* root, string code){

    if(root == nullptr){
        return;
    }

    string newcode;
    if(root->name != '#'){
        cout << root->name << " " << code << endl;
    }

    newcode = code + "0";
    tree_traversal(root->left, newcode);

    newcode = code + "1";
    tree_traversal(root->right, newcode);

}

void huffman_coding(vector<char>& sym, vector<double>& freq){

    priority_queue<tn*, vector<tn*>, comparator> heap;
    vector<tn*> nodes;

    // Create tree nodes
    for(int i=0; i<sym.size(); i++){
        tn* temp = new tn{sym[i], freq[i], nullptr, nullptr};
        nodes.push_back(temp);
    }

    // Build priority queue
    for(tn* node : nodes){
        heap.push(node);
    }

    // Construct the Huffman Tree
    while(heap.size() > 1){
        tn* item1 = heap.top(); heap.pop();
        tn* item2 = heap.top(); heap.pop();
        tn* newitem = new tn{'#', item1->val + item2->val, item1, item2};
        heap.push(newitem);
    }

    // Traverse the Huffman Tree
    tree_traversal(heap.top(), "");

}


int main(){

    // Test Case 1
    vector<char> sym = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<double> freq = {45, 13, 12, 16, 9, 5};

    cout << "\n--- First Test Case ---" << endl;
    huffman_coding(sym, freq);
    cout << endl;

    // Test Case 2
    sym = {'a', 'b', 'c', 'd', 'e'};
    freq = {0.32, 0.25, 0.20, 0.18, 0.05};

    cout << "\n--- Second Test Case ---" << endl;
    huffman_coding(sym, freq);
    cout << endl;

    return 0;
}