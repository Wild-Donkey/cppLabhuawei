#include "PoseHandler.hpp"

#include "Direction.hpp"
#include "Point.hpp"
namespace adas {

PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y),
      facing(&Direction::GetDirection(pose.heading)),
      fast(false) {}

void PoseHandler::Move() noexcept { point += facing->Move(); }
void PoseHandler::TurnLeft() noexcept { facing = &(facing->LeftOne()); }
void PoseHandler::TurnRight() noexcept { facing = &(facing->RightOne()); }
void PoseHandler::Fast() noexcept { fast ^= 1; }
bool PoseHandler::IsFast(void) const noexcept { return fast; }
Pose PoseHandler::Query(void) const noexcept {
  return Pose{point.GetX(), point.GetY(), facing->GetHeading()};
}

}  // namespace adas
