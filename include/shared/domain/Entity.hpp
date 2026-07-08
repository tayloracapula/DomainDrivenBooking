#pragma once
#include <utility>
#include "Identity.hpp"

template <typename TDerived, typename TId>
class Entity{
protected:
    explicit Entity(Identity<TId> id) : id_(std::move(id)) {}
public:
    const Identity<TId>& id() const noexcept {return id_;}

    bool sameIdentityAs(const TDerived& other) const {
	return id_ == other.id();
    }
private:
    Identity<TId> id_;
};
