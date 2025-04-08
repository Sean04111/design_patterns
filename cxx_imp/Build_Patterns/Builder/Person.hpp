//
// Created by Sean on 4/8/25.
//
#pragma once
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <iostream>

/*                Person
 *                  |
 *                  |
 *                  |
 *             PersonBuilder
 *                  |
 *                  |
 *                  |
 *           PersonBuilderBase
 *             |            |
 *             |            |
 *             |            |
 *PersonAddressBuilder    PersonJobBuilder
 *
 */

class Person;
class PersonBuilderBase;
class PersonAddressBuilder;
class PersonJobBuilder;
class PersonBuilder;

class Person {
    std::string street_address ,post_code, city;
    std::string company_name, position;
    int annual_income = 0;

    Person(){}

    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
    friend class PersonBuilder;
public:
    static PersonBuilder create();

    void introduce() const {
        std::cout <<
                "street_address : " << street_address << ", post_code : " << post_code<< ", city : " << city <<
                ", company_name : " << company_name << ", position : " << position << ", annual_income : " << annual_income <<
        std::endl;
    }
};


class PersonBuilderBase {
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person) : person(person) {}
public:

    operator Person() {
        return std::move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};


class PersonAddressBuilder : public PersonBuilderBase {
    using self = PersonAddressBuilder;
public:

    explicit PersonAddressBuilder(Person& person) : PersonBuilderBase(person) {}

    self& at(std::string street_address) {
        person.street_address = street_address;
        return * this;
    }

    self& with_postcode(std::string postcode) {
        person.post_code = postcode;
        return *this;
    }

    self& in(std::string city) {
        person.city = city;
        return *this;
    }
};

class PersonJobBuilder : public PersonBuilderBase {
    using self = PersonJobBuilder;
public:
    explicit PersonJobBuilder(Person& person) : PersonBuilderBase(person){}

    self& at(std::string company_name) {
        person.company_name = company_name;
        return *this;
    }

    self& as_a(std::string position) {
        person.position = position;
        return *this;
    }

    self& earning(int annual_income) {
        person.annual_income = annual_income;
        return *this;
    }
};

class PersonBuilder : public PersonBuilderBase {
protected:
    Person person;
public:
    PersonBuilder() : PersonBuilderBase(person) {}
};

inline PersonBuilder Person::create() {
    return PersonBuilder();
}

inline PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder(person);
}

inline PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(person);
}

#endif //PERSON_HPP
