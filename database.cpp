#include "database.h"
#include <string>
#include <iostream>

Entry *create(Type type, std::string key, void *value)
{
    Entry *newEntry = new Entry;

    newEntry -> type = type;
    newEntry -> key = key;
    newEntry -> value = value;

    return newEntry;
}


// 데이터베이스를 초기화한다.
void init(Database &database)
{

    database.entries = nullptr;
    database.size = 0;
    database.capacity = 0;

}

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry)
{
    if(database.size == database.capacity)
    {
        int newCapacity = (database.capacity == 0) ? 1: database.capacity *2;
        Entry* newEntries = new Entry[newCapacity];

        for(int i = 0; i< database.size; i++)
        {
            newEntries[i] = database.entries[i];
        }



        database.entries = newEntries;
        database.capacity = newCapacity;

    }
    database.entries[database.size] = *entry;
    database.size ++;
}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key)
{
    for(int i = 0; i< database.size; i++)
    {
        if(database.entries[i].key == key)
        {
            return &database.entries[i];
        }
    }
    return nullptr;
}

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key)
{
    for(int i = 0; i<database.size; i++)
    {
        if(database.entries[i].key == key)
        {
            // delete database.entries[i].value;

            for(int j = i; j<database.size-1; j++)
            {

              
                database.entries[j] = database.entries[j+1];


            }
            database.entries[database.size-1].key.clear();

            database.size --;
            break;
        }
    }


}

// 데이터베이스를 해제한다.
void destroy(Database &database)
{

    delete[] database.entries;

}
// 데이터베이스에 있는 값을 모두 출력한다. key : value
void list(Database &database)
{
    for(int i = 0; i<database.size; i++)
    {
        if(!database.entries[i].key.empty() )
        {
            std::cout << database.entries[i].key << ": ";

            switch (database.entries[i].type)
            {
                case INT:
                    std::cout << *(static_cast<int*>(database.entries[i].value)) << std::endl;
                    break;

                case DOUBLE:
                    std::cout << *(static_cast<double*>(database.entries[i].value)) <<std::endl;
                    break;

                case STRING:
                    std::cout << *static_cast<std::string*>(database.entries[i].value) <<std::endl;
                    break;

                default:
                    break;
            }
        }
        else
        {
            break;
        }

    }
}


