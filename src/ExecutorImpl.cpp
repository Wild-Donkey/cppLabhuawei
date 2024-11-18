#include "ExecutorImpl.hpp"

#include <map>
#include <memory>
#include <new>
#include <unordered_map>

#include "cmder\CmderFactory.hpp"
#include "core\PoseHandler.hpp"
#include "core\Singleton.hpp"

namespace adas {

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose) {}
void ExecutorImpl::Execute(const std::string& commands) noexcept {
  const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
  for (auto i : cmders) i(poseHandler).DoOperate(poseHandler);
}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor* Executor::NewExecutor(const Pose& pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);
}
}  // namespace adas