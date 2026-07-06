#pragma once
#include <optional>
#include "FullName.hpp"
#include "Address.hpp"
#include "shared/domain/Entity.hpp"
#include "shared/domain/Identity.hpp"
#include "Role.hpp"
#include "StaffId.hpp"


class StaffMember: public Entity<StaffMember, StaffId>{
public:
    //constructor
    StaffMember(
	Identity<StaffId> id, 
	FullName fullName, 
	Address address, 
	Role role, 
	std::optional<Identity<StaffId>> managerId = std::nullopt
    )
	:   Entity(std::move(id)),
	    fullName_(std::move(fullName)),
	    address_(std::move(address)),
	    role_(std::move(role)),
	    managerId_(std::move(managerId)){}
    //operators
    void updateFullName(FullName fullName) {
	fullName_ = std::move(fullName);
    }
    void changeAddress(Address address){
	address_ = std::move(address);
    }
    void changeRole(Role role){
	role_ = std::move(role);
    }
    //accessors
    const FullName& fullName() const noexcept {
	return fullName_;
    }
    const Address& address() const noexcept {
	return address_;
    }
    const Role& role() const noexcept {
	return role_;
    }
    const std::optional<Identity<StaffId>>& managerId() const noexcept {
	return managerId_;
    }

private:
    FullName fullName_;
    Address address_;
    Role role_;
    std::optional<Identity<StaffId>> managerId_;
};
