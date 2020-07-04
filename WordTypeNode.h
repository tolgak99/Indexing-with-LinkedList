#pragma once
#include "FileNameNode.h"


class WordTypeNode {
public:
    string word;
    int wordFreq;
    FileNameNode *FileNameHead;
    WordTypeNode *next;
	WordTypeNode(const string word ) :word(word), next(NULL), FileNameHead(NULL) , wordFreq(0){}
};

