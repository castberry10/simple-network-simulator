
#include "simulator.h"

// 정적 멤버 변수 초기화
double Simulator::time_ = 0.0;
std::priority_queue<Schedule, std::vector<Schedule>, std::greater<Schedule>> Simulator::scheduleQueue;
