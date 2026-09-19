#include <functional>
class EventBus {
public:
    static EventBus& instance() {
	static EventBus eventBus;

	return eventBus;
    };

    template<typename TEvent>
    void publish(const TEvent& event);

    template<typename TEvent>
    void subscribe(std::function<void(const TEvent&)> handler);
};
