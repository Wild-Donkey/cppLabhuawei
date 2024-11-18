#include "CmderFactory.hpp"

#include <functional>
#include <list>
#include <unordered_map>

namespace adas {

std::string CmderFactory::ParseCommandString(
    std::string_view commands) const noexcept {
  std::string result(commands);
  ReplaceAll(result, "TR", "T");
  return result;
}
void CmderFactory::ReplaceAll(std::string& inout, std::string_view what,
                              std::string_view with) const noexcept {
  for (std::string::size_type pos{};
       inout.npos != (pos = inout.find(what.data(), pos, what.length()));
       pos += with.length())
    inout.replace(pos, what.length(), with.data(), with.length());
}
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept {
  CmderList Rt;
  for (auto i : ParseCommandString(commands)) {
    if (cmderMap.find(i) != cmderMap.end())
      Rt.push_back((cmderMap.find(i))->second);
  }
  return Rt;
}

}  // namespace adas
