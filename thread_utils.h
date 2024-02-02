#pragma once

#include <iostream>
#include <atomic>
#include <thread>
#include <unistd.h>

#include <sys/syscall.h>

namespace Common {
  /// Set affinity for current thread to be pinned to the provided core_id.
  inline auto setThreadCore(int core_id) noexcept {
    cpu_set_t cpuset;

    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    return (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset) == 0);
  }