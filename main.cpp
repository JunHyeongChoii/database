#include <iostream>
#include <string>

#include "database.h"


void in_variable(std::string &key, std::string &type);

int main()
{
    struct Database a;
    init(a);
    while(true)
    {
        
        std::string command;

        std::cout << "command (list, add, get, del, exit): ";
        std::cin >> command;

        if(command == "list")
        {
            list(a);
        }

        else if(command == "add")
        {
            Entry *newEntry;

            std::string key;
            std::string value;
            std::string stype;
            Type type;

            in_variable(key, stype);

            std::cout << "value: ";
           
            
            if(stype == "int")
            {
                type = INT;
              
                int* value = new int;
                std::cin >> *(static_cast<int*>(value));
               
                newEntry = create(type, key, value);
            }

            else if(stype == "double")
            {
                type = DOUBLE;
           

                double* value = new double;
                std::cin >> *(static_cast<double*>(value));
          
                newEntry = create(type, key, value);
            }

            else if(stype == "string")
            {
                type = STRING;
        

                std::string* value = new std::string;
                std::cin >> *(static_cast<std::string*>(value));
           
                newEntry = create(type, key, value);
            }

            // else if(stype == "array")
            // {
            //     type = ARRAY;
            //     std::string value;
            //     std::cin >> value;
            //     newEntry = create(type, key, value);
            // }

            else
            {
                std::cout << "Unkown type\n"; 
                continue;
            }


            add(a, newEntry);
            
            
            
        }
        
        else if(command == "get")
        {
            Entry* getEntry;

            std::string key;
            std::cout << "key: ";
            std::cin >> key;
            getEntry = get(a, key);

            switch(getEntry->type)
            {
                case INT:
                    std::cout << getEntry -> key << ": " << *(static_cast<int*>(getEntry->value));
                    break;
                case DOUBLE:
                    std::cout << getEntry -> key << ": " << *(static_cast<double*>(getEntry->value));
                    break;
                case STRING:
                    std::cout << getEntry -> key << ": " << *static_cast<std::string*>(getEntry->value);
                    break;
                case ARRAY:
                    break;
                default:
                    break;

            }
            
        }

        else if(command == "del")
        {
            std::string key;

            std::cout <<"key: ";
            std::cin >> key;

            remove(a, key);

        }

        else if(command == "exit")
        {
            destroy(a);
            break;
        }
        else
        {
            std::cout << "Unkown command";
            continue;
        }

        std::cout << std::endl;
    }

    
    
}

