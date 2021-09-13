#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../include/ControlCenter.h"

int main(int argc, char* argv[]) {
    // Opening input file:
    std::ifstream commandsFile(argv[1]);
    
    // Treating exception:
    if (!commandsFile.is_open()) {
        throw "Error opening file.\n";
        exit(EXIT_FAILURE);
    }

    // Will get the commands and execute them(load the alphabet,
    // encode and decode the messages.)
    ControlCenter controlCenter;

    // Setting random seed to generate random numbers in the encoding function.
    std::srand((unsigned) std::time(NULL));
    
    controlCenter.getAndExecuteCommands(commandsFile);

    commandsFile.close();
    
    return 0;
}