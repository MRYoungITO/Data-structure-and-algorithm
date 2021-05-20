#include <sstream>
#include "ODU330.h"

ODU330::ODU330()
{

}

ODU330::~ODU330()
{

}

float ODU330::getWarnThreshold()
{
    return warnThreshold;
}

bool ODU330::setWarnThreshold(float threshold) {
    warnThreshold = threshold;
    return true;
}

float ODU330::getBER() {
    return 0.00005;  //模拟值
}

string ODU330::description()
{
    stringstream ret;
    ret << "发射功率: " << txPower << "\t发射频率: " << txFreq
        << "\t带宽: " << bandWidth << "\t误码率: " << getBER()
        << "\t告警门限: " << warnThreshold;
    return ret.str();
}
