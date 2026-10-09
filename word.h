#pragma once
#ifndef BASTA_WORD_H
#define BASTA_WORD_H

#include <iostream>
#include <string>
#include <map>

namespace words {
    void display(std::pair<std::string, int> w);
    bool over_1(std::pair<std::string, int> w);
}
#endif
