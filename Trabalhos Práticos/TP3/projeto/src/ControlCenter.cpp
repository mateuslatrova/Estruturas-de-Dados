#include "../include/ControlCenter.h"
#include "../include/BinaryTree.h"
#include <iostream> // for cout.
#include <string>

void ControlCenter::loadAlphabet(Alphabet alph) {
    for (char c: alph) {
        transliterationTree->insert(c);
    }
}

void ControlCenter::decodeMessage(EncodedMessage mess) {
    int messageSize = mess.size();
    char aux; // will hold the chars that contain the number
              // that dictates the path inside the tree.
    int gapBetweenX = 1, // initial gap, supposing that the next 'x' is
                         // right beside the first one.
        currentNum; // holds the number from aux.
    DecodedMessage decodedMessage;
    TreeNode<char>* currentNode = transliterationTree->root;
    // The above node will walk through the tree to find the correspondent
    // character for the encoding.
                             
    // For each character to be decoded:
    for (int i = 0; i < messageSize; i += gapBetweenX) {
        currentNode = transliterationTree->root; 
        gapBetweenX = 1;  

        // For each encoded character, go left or right in the tree
        // to find the correspondent decoded character.
        for (int j = i+1; mess[j] != 'x' && j < messageSize; j++) {
            aux = mess[j];
            currentNum = aux - '0'; // converting aux to int;
            
            if (currentNum % 2 == 1) // odd number -> left
                currentNode = currentNode->leftChild;
            else // even number -> right
                currentNode = currentNode->rightChild;

            gapBetweenX++;            
        }
        
        decodedMessage.push_back(currentNode->value);
    }

    // Printing result of the decoding process:
    std::cout << decodedMessage << '\n';
}

void ControlCenter::encodeMessage(DecodedMessage mess) {
    EncodedMessage encodedMessage, 
                   currentChar; // string that represents the current char to 
                                // be encrypted.
    TreeNode<char>* aux = transliterationTree->root;
    
    for (char c: mess) {
        currentChar.push_back('x'); // starts at the root.
        
        // Now, starting from the root, search where c is in the tree
        // and encode it according to the taken path.
        transliterationTree->searchAndEncode(c,aux,currentChar); 
        
        encodedMessage.append(currentChar);
        currentChar = "";
    }

    std::cout << encodedMessage << '\n';
}

ControlCenter::ControlCenter() {
    transliterationTree = new BinaryTree<char>();
}

ControlCenter::~ControlCenter() {
    delete transliterationTree;
}

void ControlCenter::getAndExecuteCommands(std::ifstream &commandsFile) {
    std::string aux;
    while (std::getline(commandsFile, aux)) {
        CommandType type = aux[0];
        int messageSize = aux.size()-begin;
        switch (type) {
            case 'A':
                {
                    Alphabet alph = aux.substr(begin,messageSize);
                    loadAlphabet(alph);
                    break;
                }
            case 'D':
                {
                    EncodedMessage encodedMessage = aux.substr(begin,messageSize);
                    decodeMessage(encodedMessage);
                    break;
                }
            case 'C':
                {
                    DecodedMessage decodedMessage = aux.substr(begin,messageSize);
                    encodeMessage(decodedMessage);
                    break;
                }
            default:
                {
                    break;
                }
            }
    }
}