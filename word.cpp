#include "word.h"

namespace words
{
    void display(std::pair<std::string, int> w){
		std::cout << w.first << "=" << w.second << ", ";
    }

    bool over_1(std::pair<std::string, int> w){
		if (w.second > 1){
			return true;
		} else {
			return false;
		}
    }
}
