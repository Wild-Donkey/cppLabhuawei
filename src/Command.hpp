#pragma once
#include <functional>

#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

namespace adas {
class MoveCommand final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    if (poseHandler.IsFast())
      poseHandler.IsReverse() ? poseHandler.Backward() : poseHandler.Forward();
    poseHandler.IsReverse() ? poseHandler.Backward() : poseHandler.Forward();
  }
};
class TurnLeftCommand final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    if (poseHandler.IsFast())
      poseHandler.IsReverse() ? poseHandler.Backward() : poseHandler.Forward();
    poseHandler.IsReverse() ? poseHandler.TurnRight() : poseHandler.TurnLeft();
  }
};
class TurnRightCommand final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    if (poseHandler.IsFast())
      poseHandler.IsReverse() ? poseHandler.Backward() : poseHandler.Forward();
    poseHandler.IsReverse() ? poseHandler.TurnLeft() : poseHandler.TurnRight();
  }
};
class FastCommand final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Fast();
  }
};
class ReverseCommand final {
 public:
  void operator()(PoseHandler& poseHandler) const noexcept {
    poseHandler.Reverse();
  }
};
}  // namespace adas