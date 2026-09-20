#include <functional>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include <vector>
class EventBus {
public:
    static EventBus& instance() {
	static EventBus eventBus;

	return eventBus;
    };

    template<typename TEvent>
    void publish(const TEvent& event){
	auto it = handlers_.find(std::type_index(typeid(TEvent)));

	if (it == handlers_.end()) {
	    return;
	}

	for (const auto& handler : it->second) {
	    handler(&event);
	}
    }

    template<typename TEvent>
    void subscribe(std::function<void(const TEvent&)> handler){

	auto wrapper =  [handler = std::move(handler)] (const void* event) {
	    handler(*static_cast<const TEvent*>(event));
	};

	handlers_[std::type_index(typeid(TEvent))]
	    .push_back(std::move(wrapper));
    }

private:
    using Handler = std::function<void(const void*)>;

    std::unordered_map<std::type_index, std::vector<Handler>> handlers_;

    EventBus() = default;
};
