#ifndef CONTROL_CENTER_H
#define CONTROL_CENTER_H

#include "Messages.h"
#include <fstream> // for ifstream.

// Forward declaration:
template <class T>
class BinaryTree;

#define begin 3 // index of the command string where the actual message starts.

class ControlCenter {
    
    private:
        BinaryTree<char>* transliterationTree;

        void loadAlphabet(Alphabet alph);
        void decodeMessage(EncodedMessage mess);
        void encodeMessage(DecodedMessage mess);

    public:
        ControlCenter();
        ~ControlCenter();
        void getAndExecuteCommands(std::ifstream &commandsFile);
};

#endif