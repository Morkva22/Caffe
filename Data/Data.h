#ifndef DATA_H
#define DATA_H

#include <.../.../lib/lib.h>
class Data {
public:
    void createFileIfNotExists(const string& filename);
    void saveData(const string& data);
    string loadData();
    int getLastOrderNumber();
};

#endif
