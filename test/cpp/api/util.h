#pragma once

#include <torch/nn/cloneable.h>

#include <string>
#include <utility>

namespace torch {

// Lets you use a container without making a new class,
// for experimental implementations
class SimpleContainer : public nn::Cloneable<SimpleContainer> {
 public:
  void reset() override {}

  template <typename ModuleHolder>
  ModuleHolder add(
      ModuleHolder module_holder,
      std::string name = std::string()) {
    return Module::register_module(std::move(name), module_holder);
  }
};
} // namespace torch
