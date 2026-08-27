#pragma once
template<
    typename TDto,
    typename TResult
>
class IUseCase{
public:
    virtual TResult execute(const TDto& dto) = 0;

    virtual ~IUseCase() = default;
};
