#pragma once

#include<string>
#include<iostream>

using namespace std;

class FileNameNode {
public:
    string fileName;
    FileNameNode *next;
    FileNameNode(const string fname) :fileName(fname), next(NULL) {}
};