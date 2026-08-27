#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"

class GetStaffMember : public IUseCase<GetDTO<Identity<StaffId>>, StaffMember>
{
public:
    GetStaffMember(
	IStaffRepository& staffRepository)
    :	staffRepository_(staffRepository)
    {}

    StaffMember execute(const GetDTO<Identity<StaffId>>& dto) override;
private:
    IStaffRepository& staffRepository_;
};
