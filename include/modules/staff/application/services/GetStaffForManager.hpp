#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"
#include <vector>

class GetStaffForManager: public IUseCase<GetDTO<Identity<StaffId>>, std::vector<StaffMember>>
{
public:
    GetStaffForManager(
	IStaffRepository& staffRepository)
    :	staffRepository_(staffRepository)
    {}

    std::vector<StaffMember> execute(const GetDTO<Identity<StaffId>>& dto) override;
private:
    IStaffRepository& staffRepository_;
};
