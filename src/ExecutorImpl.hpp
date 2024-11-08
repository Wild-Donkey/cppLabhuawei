#pragma once
#include <string>

#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas {

class ExecutorImpl final : public Executor {
 public:
  // 构造函数
  explicit ExecutorImpl(const Pose& pose) noexcept;

  // 默认析构函数
  ~ExecutorImpl() noexcept = default;

  // 不能拷贝
  ExecutorImpl(const ExecutorImpl&) = delete;

  // 不能赋值
  ExecutorImpl& operator=(const ExecutorImpl&) = delete;

 public:
  // 查询当前汽车姿态，是父类抽象方法Query的具体实现
  Pose Query(void) const noexcept override;
  void Execute(const std::string& commands) noexcept override;

 private:
  PoseHandler poseHandler;
};

}  // namespace adas
