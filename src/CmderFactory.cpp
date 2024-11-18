#include "CmderFactory.hpp"

#include <functional>
#include <list>
#include <unordered_map>

namespace adas {

CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept {
  CmderList Rt;
  char Flg = 0;
  for (auto i : commands) {
    if (Flg) {
      Flg = 0;
      continue;
    }
    if (cmderMap.find(i) != cmderMap.end())
      Rt.push_back((cmderMap.find(i))->second);
    // else
    // Flg = 1, Rt.push_back(TurnRoundCommand());
  }
  return Rt;
}

}  // namespace adas