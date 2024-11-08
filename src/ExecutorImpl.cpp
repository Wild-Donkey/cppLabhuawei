#include "ExecutorImpl.hpp"

#include <map>
#include <memory>
#include <new>

#include "Command.hpp"
#include "PoseHandler.hpp"

namespace adas {

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose) {}
void ExecutorImpl::Execute(const std::string& commands) noexcept {
  for (auto i : commands) {
    std::unique_ptr<ICommand> cmder;
    if (i == 'F') cmder = std::make_unique<FastCommand>();
    if (i == 'M') cmder = std::make_unique<MoveCommand>();
    if (i == 'L') cmder = std::make_unique<TurnLeftCommand>();
    if (i == 'R') cmder = std::make_unique<TurnRightCommand>();
    cmder->DoOperate(poseHandler);
  }
}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor* Executor::NewExecutor(const Pose& pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);
}
}  // namespace adas