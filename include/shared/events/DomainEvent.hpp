#include <chrono>
class DomainEvent
{
public: 
    virtual ~DomainEvent() = default;

protected:
    DomainEvent()
	: occuredOn_(
	std::chrono::system_clock::now())
    {}
private:
    std::chrono::system_clock::time_point occuredOn_;
};
