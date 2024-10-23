#include "ExecutorImpl.hpp"

#include <map>
#include <new>
#include <memory>

namespace adas {
  void ExecutorImpl::Execute(const std::string& commands) noexcept {
    for (auto i : commands) {
      if (i == 'F') {
        isFast ^= 1;
        continue;
      }
      if (isFast) {
        std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
        cmder->DoOperate(*this);
      }
      if (i == 'M') {
        std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
        cmder->DoOperate(*this);
      }
      if (i == 'L') {
        std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
        cmder->DoOperate(*this);
      }
      if (i == 'R') {
        std::unique_ptr<TurnRightCommand> cmder = std::make_unique<TurnRightCommand>();
        cmder->DoOperate(*this);
      }
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