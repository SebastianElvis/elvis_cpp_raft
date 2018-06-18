//
// Created by elvis on 18/06/18.
//

#include <iostream>
#include <string>
#include "Shell.h"

using namespace std;

void Shell::help()
{
    cout << "Fuck you!" << endl;
}

void Shell::start()
{
    while(true) {
        cout << "> ";

        string c;
        cin >> c;

        if(c == "exit") {
            cout << "Bye" << endl;
            exit(0);
        } else if (c == "help") {
            help();
        } else {
            cout << c << endl;
        }
    }

}