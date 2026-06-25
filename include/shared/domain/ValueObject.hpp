#pragma once

class ValueObject {
protected:
    ValueObject() = default;	
public:
    virtual ~ValueObject() = default;
bool operator==(const ValueObject& other) const = default;

};
