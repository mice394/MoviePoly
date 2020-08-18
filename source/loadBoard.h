#ifndef _LOADBOARD_H
#define _LOADBOARD_H

#include "board.h"

#include <string>

class LoadBoard: public Board {
	private:
		std::string saveFile;
    public:
        void init();

};

#endif
