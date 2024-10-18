#include "ExecutorImpl.hpp"

#include <map>
#include <new>

namespace adas {
ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}
Pose ExecutorImpl::Query(void) const noexcept { return pose; }
Executor *Executor::NewExecutor(const Pose &pose) noexcept {
  return new (std::nothrow) ExecutorImpl(pose);
}
void ExecutorImpl::Execute(const std::string &commands) noexcept {
  std::map<char, std::pair<int, int> > Dire;
  std::map<char, char> Lef, Rig;
  Dire['E'] = {1, 0};
  Dire['W'] = {-1, 0};
  Dire['S'] = {0, -1};
  Dire['N'] = {0, 1};
  Rig[Lef['E'] = 'N'] = 'E';
  Rig[Lef['W'] = 'S'] = 'W';
  Rig[Lef['S'] = 'E'] = 'S';
  Rig[Lef['N'] = 'W'] = 'N';
  for (auto i : commands) {
    if (i == 'M') {
      pose.x += Dire[pose.heading].first;
      pose.y += Dire[pose.heading].second;
    }
  }
}
}  // namespace adas
