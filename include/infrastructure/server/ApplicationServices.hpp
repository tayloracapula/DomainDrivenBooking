#include"modules/staff/application/services/CreateStaffMember.hpp"


class ApplicationServices {
public:
    static ApplicationServices& instance();

    void initialise();

    CreateStaffMember& createStaffMember();
private:
};
