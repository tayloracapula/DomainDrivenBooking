#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/UpdateStaffRoleDTO.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/staff/application/dto/AssignManagerDTO.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"

class UpdateStaffRole : public IUseCase<UpdateStaffRoleDTO, Identity<StaffId>>
{
public:
    UpdateStaffRole(
	IStaffRepository& staffRepository)
    :   staffRepository_(staffRepository)
    {}
    Identity<StaffId> execute(const UpdateStaffRoleDTO& dto) override;
private:
    IStaffRepository& staffRepository_;
};
