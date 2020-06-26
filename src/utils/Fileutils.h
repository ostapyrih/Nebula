//
// Created by ostap on 6/23/2020.
//
#pragma once

#include <string>

namespace nebula::utils
{

    inline std::string read_file(const char *filepath)
    {
        FILE *file;
        fopen_s(&file, filepath, "rt");
        fseek(file, 0, SEEK_END);
        unsigned long length = ftell(file);
        char *data = new char[length + 1];
        memset(data, 0, length + 1);
        fseek(file, 0, SEEK_SET);
        fread(data, 1, length, file);
        fclose(file);

        std::string result(data);
        delete[] data;

        return result;
    }

}