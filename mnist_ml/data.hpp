#ifndef __DATA_H
#define __DATA_H

#include <vector>
#include "stdint.h"
#include "stdio.h"

class data 
{
    std::vector<uint8_t> * feature_vector;
    unint8_t label; 
    int enum_label; 
}

#endif