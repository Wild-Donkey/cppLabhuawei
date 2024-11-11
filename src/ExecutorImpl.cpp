#include "ExecutorImpl.hpp"

#include <map>
#include <memory>
#include <new>
#include <unordered_map>

#include "Command.hpp"
#include "PoseHandler.hpp"

namespace adas {

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose) {}
void ExecutorImpl::Execute(const std::string& commands) noexcept {
  std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)> >
      cmderMap;
  MoveCommand moveCommand;
  cmderMap.emplace('M', moveCommand.operate);
  FastCommand fastCommand;
  cmderMap.emplace('F', fastCommand.operate);
  TurnLeftCommand turnLeftCommand;
  cmderMap.emplace('L', turnLeftCommand.operate);
  TurnRightCommand turnRightCommand;
  cmderMap.emplace('R', turnRightCommand.operate);
  for (auto i : commands) {
    const auto it = cmderMap.find(i);
    if (it != cmderMap.end()) it->second(poseHandler);
  }
}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor* Executor::NewExecutor(const Pose& pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);
}
}  // namespace adas