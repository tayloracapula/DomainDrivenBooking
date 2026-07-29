#pragma once
#include "optional"
#include "shared/domain/Identity.hpp"
template<
    typename Taggregate,
    typename TId
>
class IRepository{
public:
    virtual void save( const Taggregate& aggregate) = 0; 

    virtual std::optional<Taggregate> findById(const Identity<TId>& id) = 0;
    virtual ~IRepository() = default;
};
