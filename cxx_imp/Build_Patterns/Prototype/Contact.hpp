//
// Created by Sean on 4/11/25.
//

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Address {
public:
    std::string street, city;
    int suite;
    Address(const std::string& street, const std::string& city, const int suite) : street(street), city(city), suite(suite) {}

    virtual Address* clone() {
        return new Address{street, city, suite};
    };
};

class Contact {
public:
    std::string name;
    Address* address;

    Contact(const Contact& other) : name(other.name){
        address = new Address(
            other.address->street,
            other.address->city,
            other.address->suite
            );

    }
};

class ExtendedAddress : public Address {
    std::string country, postcode;

    ExtendedAddress(const std::string& street, const std::string& city, const int suite, const std::string& country, const std::string& postcode)
    : Address(street, city, suite), country(country), postcode(postcode) {}

    ExtendedAddress(const ExtendedAddress& other) : Address(other) , country(other.country), postcode(other.postcode) {}

    ExtendedAddress* clone() override {
        return new ExtendedAddress(*this);
    }

};

void use() {
    ExtendedAddress ea = ExtendedAddress();
    Address& a = ea;
    auto cloned = a.clone();
}

#endif //CONTACT_HPP
