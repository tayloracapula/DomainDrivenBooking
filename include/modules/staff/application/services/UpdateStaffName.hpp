#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/UpdateStaffNameDTO.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/staff/application/dto/AssignManagerDTO.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"

class UpdateStaffName : public IUseCase<UpdateStaffNameDTO, Identity<StaffId>>
{
public:
    UpdateStaffName(
	IStaffRepository& staffRepository)
    :   staffRepository_(staffRepository)
    {}
    Identity<StaffId> execute(const UpdateStaffNameDTO& dto) override;
private:
    IStaffRepository& staffRepository_;
};
