#pragma once
#include <functional>

#include "ExecutorImpl.hpp"
#include "cmder\CmderOrchestrator.hpp"
#include "core\PoseHandler.hpp"

namespace adas {
class MoveCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    return orchestrator.Move(poseHandler);
  }
};
class TurnLeftCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    return orchestrator.TurnLeft(poseHandler);
  }
};
class TurnRightCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    return orchestrator.TurnRight(poseHandler);
  }
};
class FastCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    ActionGroup actionGroup;
    actionGroup.PushAction(ActionType::BE_FAST_ACTION);
    return actionGroup;
  }
};
class ReverseCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    ActionGroup actionGroup;
    actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
    return actionGroup;
  }
};
class TurnRoundCommand final {
 public:
  ActionGroup operator()(const PoseHandler& poseHandler,
                         const CmderOrchestrator& orchestrator) const noexcept {
    return orchestrator.TurnRound(poseHandler);
  }
};
}  // namespace adas