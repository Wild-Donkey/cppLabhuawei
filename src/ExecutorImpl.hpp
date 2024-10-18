#pragma once
#include <string>

#include "Executor.hpp"

namespace adas {

class ExecutorImpl : public Executor {
 public:
  // 构造函数
  explicit ExecutorImpl(const Pose &pose) noexcept;

  // 默认析构函数
  ~ExecutorImpl() noexcept = default;

  // 不能拷贝
  ExecutorImpl(const ExecutorImpl &) = delete;

  // 不能赋值
  ExecutorImpl &operator=(const ExecutorImpl &) = delete;

 public:
  // 查询当前汽车姿态，是父类抽象方法Query的具体实现
  Pose Query(void) const noexcept override;

 private:
  // 私有数据成员，汽车当前姿态
  Pose pose;
};

}  // namespace adas
