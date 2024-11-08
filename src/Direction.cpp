
#include "Direction.hpp"

namespace adas {

static const Direction directions[4] = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}};
static const Point points[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
Direction::Direction(const unsigned index, const char heading) noexcept
    : index(index), heading(heading) {}
const Direction& Direction::GetDirection(const char heading) noexcept {
  if (heading == 'E') return directions[0];
  if (heading == 'S') return directions[1];
  if (heading == 'W') return directions[2];
  return directions[3];
}
const Point& Direction::Move(void) const noexcept { return points[index]; }
const Direction& Direction::LeftOne(void) const noexcept {
  return directions[(index - 1) & 3];
}
const Direction& Direction::RightOne(void) const noexcept {
  return directions[(index + 1) & 3];
}
const char Direction::GetHeading(void) const noexcept { return heading; }

}  // namespace adas
