#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/CreateStaffMemberDTO.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/staff/application/dto/AssignManagerDTO.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"


class CreateStaffMember : public IUseCase<CreateStaffMemberDTO, Identity<StaffId>>
{
public:
    CreateStaffMember(
	IStaffRepository& staffRepository)
    :   staffRepository_(staffRepository)
    {}
    Identity<StaffId> execute(const CreateStaffMemberDTO& dto) override;
private:
    IStaffRepository& staffRepository_;
};
