#pragma once
#include "FullName.hpp"
#include "Address.hpp"
#include "shared/domain/Entity.hpp"
#include "shared/domain/Identity.hpp"

struct StaffId{};

class StaffMember: public Entity<StaffMember, StaffId>{
public:

    StaffMember(Identity<StaffId> id, FullName fullName, Address address)
	:   Entity(std::move(id)),
	    fullName_(std::move(fullName)),
	    address_(std::move(address)) {}

    void updateFullName(const FullName& fullName) {
	fullName_ = fullName;
    }

    void changeAddress(const Address& address){
	address_ = address;
    }

    const FullName& fullName() const noexcept {
	return fullName_;
    }

    const Address& address() const noexcept {
	return address_;
    }

private:
    FullName fullName_;
    Address address_;
};
