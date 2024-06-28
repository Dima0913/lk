#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
public:
    Person() : name("") {}
    Person(const string& name) : name(name) {}
    Person(const Person& other) : name(other.name) {}
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }

    ~Person() {}

    void print() const {
        cout << "Person: " << name << endl;
    }
};

class Apartment {
private:
    Person* residents;
    int residentCount;
public:
    Apartment() : residents(nullptr), residentCount(0) {}

    Apartment(Person* residents, int count) {
        residentCount = count;
        this->residents = new Person[count];
        for (int i = 0; i < count; i++) {
            this->residents[i] = residents[i];
        }
    }

    Apartment(const Apartment& other) {
        residentCount = other.residentCount;
        residents = new Person[residentCount];
        for (int i = 0; i < residentCount; i++) {
            residents[i] = other.residents[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this != &other) {
            delete[] residents;
            residentCount = other.residentCount;
            residents = new Person[residentCount];
            for (int i = 0; i < residentCount; i++) {
                residents[i] = other.residents[i];
            }
        }
        return *this;
    }

    ~Apartment() {
        delete[] residents;
    }

    void print() const {
        cout << "Apartment with " << residentCount << " residents:" << endl;
        for (int i = 0; i < residentCount; i++) {
            residents[i].print();
        }
    }
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;
public:
    House() : apartments(nullptr), apartmentCount(0) {}

    House(Apartment* apartments, int count) {
        apartmentCount = count;
        this->apartments = new Apartment[count];
        for (int i = 0; i < count; i++) {
            this->apartments[i] = apartments[i];
        }
    }

    House(const House& other) {
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this != &other) {
            delete[] apartments;
            apartmentCount = other.apartmentCount;
            apartments = new Apartment[apartmentCount];
            for (int i = 0; i < apartmentCount; i++) {
                apartments[i] = other.apartments[i];
            }
        }
        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void print() const {
        cout << "House with " << apartmentCount << " apartments:" << endl;
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i].print();
        }
    }
};

int main() {
    Person p1("John Doe");
    Person p2("Jane Smith");
    Person p3("Alice Johnson");
    Person p4("Bob Brown");

    Person residents1[] = { p1, p2 };
    Apartment a1(residents1, 2);

    Person residents2[] = { p3, p4 };
    Apartment a2(residents2, 2);

    Apartment apartments[] = { a1, a2 };
    House h1(apartments, 2);

    h1.print();
}