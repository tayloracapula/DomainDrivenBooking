#pragma once

#include <string>
#include <utility>
using string = std::string;
template<
typename TId
>
struct GetDTO{
    explicit GetDTO(TId id)
	:id(std::move(id))
    {}
    TId id;
};
