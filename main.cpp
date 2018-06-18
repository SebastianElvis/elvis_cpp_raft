#include <iostream>
#include <shell/Shell.h>
#include "network/Server.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Server s();
    Shell shell;
    shell.start();
    return 0;
}