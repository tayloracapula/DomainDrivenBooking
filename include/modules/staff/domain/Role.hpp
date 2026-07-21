#include "shared/domain/ValueObject.hpp"
#include "RoleType.hpp"

class Role : ValueObject {
public:
    //constructors
    Role (RoleType role) {
	role_ = role;
    }
    //accessors
    const RoleType role() const noexcept{
	return role_;
    }

    bool isManager() const noexcept {
	return role_ == RoleType::Manager;
    }

    bool isAdmin() const noexcept {
	return role_ == RoleType::Administrator;
    }
private:
    RoleType role_;
};
