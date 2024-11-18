#pragma once
#include "NormalOrchestrator.hpp"
namespace adas {
class SportsCarOrchestrator : public NormalOrchestrator {
 public:
  ActionGroup Move(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(GetStepAction(poseHandler));
    actionGroup.PushAction(GetStepAction(poseHandler));
    return actionGroup;
  }
  ActionGroup TurnLeft(const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::TURNRIGHT_ACTION
                               : ActionType::TURNLEFT_ACTION);
    actionGroup.PushAction(GetStepAction(poseHandler));
    return actionGroup;
  }
  ActionGroup TurnRight(
      const PoseHandler& poseHandler) const noexcept override {
    ActionGroup actionGroup;
    actionGroup += OnFast(poseHandler);
    actionGroup.PushAction(poseHandler.IsReverse()
                               ? ActionType::TURNLEFT_ACTION
                               : ActionType::TURNRIGHT_ACTION);
    actionGroup.PushAction(GetStepAction(poseHandler));
    return actionGroup;
  }
};
}  // namespace adas