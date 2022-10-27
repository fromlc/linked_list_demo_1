//----------------------------------------------------------
// CS 281-0798, Fall 2020
//
// Week 6 Example Code #1
// Signature linked list data types
//
// A linked list node, or data item plus pointer, can be 
//      1) a named structure or
//      2) a class.
//
// When you see a data structure that includes a pointer 
// to itself, you're seeing the signature of a linked list.
//----------------------------------------------------------

#include <iostream>

    // A linked list node can use a struct
    struct s_Node {
        int   data;
        struct s_Node* next;
    };

    // A linked list node can use a class instance
    class Node {
    private:
    public:
        int   data;
        Node* next;

        Node() : data(0), next(nullptr) {}
    };

//----------------------------------------------------------
// main() entry point 
//----------------------------------------------------------
int main()
{
    // syntax for using struct nodes
    struct s_Node* p_sN = new s_Node;
    std::cout << "(struct) p_sN.data: " << p_sN->data << std::endl;
    std::cout << "(struct) p_sN.next: " << p_sN->next << std::endl;

    std::cout << std::endl;

    // syntax for using a class instance
    Node* cN = new Node;
    std::cout << "(class instance) cN->data: " << cN->data << std::endl;
    std::cout << "(class instance) cN->next: " << cN->next << std::endl;

    // Note that the Node class constructor
    // initialized members for us :-)
    // We have to initialize the struct
    // values ourselves :-(

    std::cout << std::endl;
    system("pause");

    return 0;
}