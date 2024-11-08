#include "PoseHandler.hpp"

namespace adas {

PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose), fast(false) {}

void PoseHandler::Move() noexcept {
  if (IsFast()) {
    if (pose.heading == 'E' || pose.heading == 'W')
      pose.x += (pose.heading == 'E' ? 1 : -1);
    else
      pose.y += (pose.heading == 'N' ? 1 : -1);
  }
  if (pose.heading == 'E' || pose.heading == 'W')
    pose.x += (pose.heading == 'E' ? 1 : -1);
  else
    pose.y += (pose.heading == 'N' ? 1 : -1);
}
void PoseHandler::TurnLeft() noexcept {
  if (IsFast()) {
    if (pose.heading == 'E' || pose.heading == 'W')
      pose.x += (pose.heading == 'E' ? 1 : -1);
    else
      pose.y += (pose.heading == 'N' ? 1 : -1);
  }
  if (pose.heading == 'E')
    pose.heading = 'N';
  else if (pose.heading == 'W')
    pose.heading = 'S';
  else if (pose.heading == 'S')
    pose.heading = 'E';
  else
    pose.heading = 'W';
}
void PoseHandler::TurnRight() noexcept {
  if (IsFast()) {
    if (pose.heading == 'E' || pose.heading == 'W')
      pose.x += (pose.heading == 'E' ? 1 : -1);
    else
      pose.y += (pose.heading == 'N' ? 1 : -1);
  }
  if (pose.heading == 'N')
    pose.heading = 'E';
  else if (pose.heading == 'S')
    pose.heading = 'W';
  else if (pose.heading == 'E')
    pose.heading = 'S';
  else
    pose.heading = 'N';
}
void PoseHandler::Fast() noexcept { fast ^= 1; }
bool PoseHandler::IsFast(void) const noexcept { return fast; }
Pose PoseHandler::Query(void) const noexcept { return pose; }

}  // namespace adas
