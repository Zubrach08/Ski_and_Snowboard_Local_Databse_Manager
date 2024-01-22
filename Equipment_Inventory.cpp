#include <iostream>
#include "Command_Executer.hpp"
#include "stdlib.h"


int main()
{
    while (true) {
        system("cls");
        std::cout << "0: Close program \n";  
        std::cout << "1 : Number of items currently stored\n";
        std::cout << "2 : Search by id\n";
        std::cout << "3 : Search by Filter\n";
        std::cout << "4: Delete a model(by id)   \n";
        std::cout << "5: Replace a filter\n";
        std::cout << "6: Add a model\n";
        std::cout << std::endl;
        std::cout << "Enter command type : ";
        int command_type; std::cin >> command_type;
        if (!cmdex::Execute_Command(command_type)) break;
    }
}
