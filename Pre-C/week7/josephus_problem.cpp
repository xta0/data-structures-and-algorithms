#include <iostream>

using namespace std;

struct Node{
    int index;
    Node* next;
    Node* prev;
    Node(int index){
        this->index = index;
    }
};

int main(){

    unique_ptr<Node> rootNode(new Node(1));
    


    return 0;
}