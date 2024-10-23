#pragma once
#include <string>

#include "Executor.hpp"

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
    class ICommand {
    public:
      virtual ~ICommand() {}
      virtual void DoOperate(ExecutorImpl& executor)const = 0;
    };
    class MoveCommand final : public ICommand {
    public:
      void DoOperate(ExecutorImpl& executor) const noexcept override { executor.Move(); }
    };
    class TurnLeftCommand final : public ICommand {
    public:
      void DoOperate(ExecutorImpl& executor) const noexcept override { executor.TurnLeft(); }
    };
    class TurnRightCommand final : public ICommand {
    public:
      void DoOperate(ExecutorImpl& executor) const noexcept override { executor.TurnRight(); }
    };
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    Pose pose;
    bool isFast;
  };

}  // namespace adas
