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
                (*value).insert(0,"\"");
                (*value).push_back('\"');
                newEntry = create(type, key, value);
            }

            // else if(stype == "array")
            // {
            //     type = ARRAY;
            //     Array* value = new Array;
            //     int size;

            //     std::cout << size <": ";
            //     std::cin >>size;

            //     for(int i = 0 ; i<size; i++)
            //     {
            //         std::cout << item[i] <<": ";
            //         std::cin >> ;
            //         for(int j = 0; j<size; j++)
            //         {
            //             std::cout<< item[j] <<": ";
            //             std::cin >> ;
            //         }
            //     }
            //     std::cout << size;

            //     std::cin >> value;


            //     newEntry = create(type, key, value);
            // }

            else
            {
                std::cout << "Unkown type\n"; 
                continue;
            }
            
            int keyCheck = 0; // 0이면 중복되는 key값이 없는것, 1이면 중복되는 key값이 있는것

            int numi = 0; // i값을 저장해서 같은 key값의 위치를 찾는다.
           for(int i = 0; i<a.size; i++)
           {
                if(a.entries[i].key == key)
                {
                    keyCheck = 1;
                    numi = i;
                }
           }

           if(keyCheck == 0)
           {
                add(a, newEntry);
           }
           
           else
           {
                a.entries[numi] = *newEntry;
           }
            
            
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

