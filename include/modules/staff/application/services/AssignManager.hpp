#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/staff/application/dto/AssignManagerDTO.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"

class AssignManager: public IUseCase<AssignManagerDTO, Identity<StaffId>>
{
public:
    AssignManager(
	IStaffRepository& staffRepository)
    :   staffRepository_(staffRepository)
    {}
    Identity<StaffId> execute(const AssignManagerDTO& dto) override;
private:
    IStaffRepository& staffRepository_;
};
