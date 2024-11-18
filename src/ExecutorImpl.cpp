#include "ExecutorImpl.hpp"

#include <map>
#include <memory>
#include <new>
#include <unordered_map>

#include "cmder\BusOrchestrator.hpp"
#include "cmder\CmderFactory.hpp"
#include "cmder\CmderOrchestrator.hpp"
#include "cmder\NormalOrchestrator.hpp"
#include "cmder\SportsCarOrchestrator.hpp"
#include "core\PoseHandler.hpp"
#include "core\Singleton.hpp"

namespace adas {

ExecutorImpl::ExecutorImpl(const Pose& pose,
                           CmderOrchestrator* orchestrator) noexcept
    : poseHandler(pose), orchestrator(orchestrator) {}
void ExecutorImpl::Execute(const std::string& commands) noexcept {
  const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
  for (auto i : cmders) i(poseHandler, *orchestrator).DoOperate(poseHandler);
}
Pose ExecutorImpl::Query(void) const noexcept { return poseHandler.Query(); }
Executor* Executor::NewExecutor(const Pose& pose,
                                const ExecutorType executorType) noexcept {
  CmderOrchestrator* orchestrator = nullptr;
  switch (executorType) {
    case ExecutorType::NORMAL: {
      orchestrator = new (std::nothrow) NormalOrchestrator();
      break;
    }
    case ExecutorType::SPORTS_CAR: {
      orchestrator = new (std::nothrow) SportsCarOrchestrator();
      break;
    }
    case ExecutorType::BUS: {
      orchestrator = new (std::nothrow) BusOrchestrator();
      break;
    }
  }
  return new (std::nothrow) ExecutorImpl(pose, orchestrator);
}
}  // namespace adas