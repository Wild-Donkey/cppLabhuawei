#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

namespace adas {
class ICommand {
 public:
  virtual ~ICommand() {}
  virtual void DoOperate(PoseHandler& executor) const = 0;
};
class MoveCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler& poseHandler) const noexcept override {
    poseHandler.Move();
  }
};
class TurnLeftCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler& poseHandler) const noexcept override {
    poseHandler.TurnLeft();
  }
};
class TurnRightCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler& poseHandler) const noexcept override {
    poseHandler.TurnRight();
  }
};
class FastCommand final : public ICommand {
 public:
  void DoOperate(PoseHandler& poseHandler) const noexcept override {
    poseHandler.Fast();
  }
};
}  // namespace adas