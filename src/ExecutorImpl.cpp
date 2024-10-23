#include "ExecutorImpl.hpp"

#include <map>
#include <new>

namespace adas {
  void ExecutorImpl::Execute(const std::string& commands) noexcept {
    for (auto i : commands) {
      if (i == 'F') {
        isFast ^= 1;
        continue;
      }
      if (isFast) Move();
      if (i == 'M') Move();
      if (i == 'L') TurnLeft();
      if (i == 'R') TurnRight();
    }
  }
  void ExecutorImpl::Move() noexcept {
    if (pose.heading == 'E' || pose.heading == 'W')
      pose.x += (pose.heading == 'E' ? 1 : -1);
    else
      pose.y += (pose.heading == 'N' ? 1 : -1);
  }
  void ExecutorImpl::TurnLeft() noexcept {
    if (pose.heading == 'E') pose.heading = 'N';
    else if (pose.heading == 'W') pose.heading = 'S';
    else if (pose.heading == 'S') pose.heading = 'E';
    else pose.heading = 'W';
  }
  void ExecutorImpl::TurnRight() noexcept {
    if (pose.heading == 'N') pose.heading = 'E';
    else if (pose.heading == 'S') pose.heading = 'W';
    else if (pose.heading == 'E') pose.heading = 'S';
    else pose.heading = 'N';
  }
  ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
    : pose(pose), isFast(false) {
  }
  Pose ExecutorImpl::Query(void) const noexcept { return pose; }
  Executor* Executor::NewExecutor(const Pose& pose) noexcept {
    return new (std::nothrow) ExecutorImpl(pose);
  }
}  // namespace adas