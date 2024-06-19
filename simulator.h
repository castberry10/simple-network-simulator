#ifndef SIMULATOR_H
#define SIMULATOR_H

#define RANDOM_SEED 369369

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

class Simulator;

class Schedule {
private:

  double time_;
  std::function<void()> function_;
public:
  double time() { return time_; }
  void call() { function_(); }

  Schedule(double time, std::function<void()> function)
      : time_(time), function_(function) {}
  
  bool operator>(const Schedule& other) const {
        return time_ > other.time_;
  }
};

// std::priority_queue<std::function<void()>> scheduleQueue;
  
class Simulator {
private:
  static double time_;
  static std::priority_queue<Schedule, std::vector<Schedule>, std::greater<Schedule>> scheduleQueue;
public:
  static double now() { return time_; }

  static void prepare() { srand(RANDOM_SEED); }

  static void schedule(double time, std::function<void()> function) {
    // 스케줄 큐에 스케줄을 추가한다.
    // TODO: 구현
    // scheduleQueue.push()
    scheduleQueue.push(Schedule(time, function));
  }

  static void run() {
    // 모든 스케줄을 실행한다.
    // TODO: 구현
    while(scheduleQueue.size() > 0){
      Schedule schedule_ = scheduleQueue.top();
      time_ = schedule_.time();
      schedule_.call();
      scheduleQueue.pop();
    }
  }
};

#endif