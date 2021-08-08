#pragma once


#define noused(x) (void)(x)
enum class phazeType {
    Start,
    Instantly,
    End
};

using Involve = std::function<int()>;  // int - кол-во оставшихся раз воздействия