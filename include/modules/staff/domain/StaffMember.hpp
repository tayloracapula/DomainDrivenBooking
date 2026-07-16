#pragma once
#include <optional>
#include "FullName.hpp"
#include "Address.hpp"
#include "EmploymentStatus.hpp"
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
    :   
	Entity(std::move(id)),
        fullName_(std::move(fullName)),
        address_(std::move(address)),
        role_(std::move(role)),
        managerId_(std::move(managerId)),
	employmentStatus_(EmploymentStatus::Active)
    {}
    //operators
    void changeFullName(FullName fullName) {
	fullName_ = std::move(fullName);
    }
    void changeAddress(Address address){
	address_ = std::move(address);
    }
    void changeRole(Role role){
	role_ = std::move(role);
    }
    void changeEmploymentStatus(EmploymentStatus status){
	employmentStatus_ = std::move(status);
    }
    void changeManager(std::optional<Identity<StaffId>> managerId){
	managerId_ = managerId;
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
    const EmploymentStatus& employmentStatus() const noexcept {
	return employmentStatus_;
    }
    const std::optional<Identity<StaffId>>& managerId() const noexcept {
	return managerId_;
    }

private:
    FullName fullName_;
    Address address_;
    Role role_;
    EmploymentStatus employmentStatus_;
    std::optional<Identity<StaffId>> managerId_;
};
