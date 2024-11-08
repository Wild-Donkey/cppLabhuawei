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
  std::unordered_map<char, std::unique_ptr<ICommand> > cmderMap;
  cmderMap.emplace('M', std::make_unique<MoveCommand>());
  cmderMap.emplace('F', std::make_unique<FastCommand>());
  cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
  cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
  for (auto i : commands) {
    const auto it = cmderMap.find(i);
    if (it != cmderMap.end()) it->second->DoOperate(poseHandler);
  }
}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor* Executor::NewExecutor(const Pose& pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);
}
}  // namespace adas