#include <utility>

template <typename T>
class Entity{
    private:
	T id_;	
    protected:
	explicit Entity(T id) : id_(std::move(id)) {}
    public:
	virtual ~Entity() = default;

	const T id() const noexcept {return id_;}

	bool sameIdentityAs(const Entity& other) const {return id_ == other.id_;}
};
