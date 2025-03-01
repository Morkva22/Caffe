#ifndef DATA_H
#define DATA_H

#include <.../.../lib/lib.h>
class Data {
public:
    void createFileIfNotExists(const std::string& filename);
    void saveData(const std::string& data);
    std::string loadData();
    int getLastOrderNumber();
};

#endif