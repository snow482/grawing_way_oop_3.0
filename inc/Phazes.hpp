#pragma once


#define noused(x) (void)(x)

enum class phazeType {
    Start = 1,
    Instantly = 2,
    End = 3
};

using Involve = std::function<int()>;  // int - кол-во оставшихся раз воздействия