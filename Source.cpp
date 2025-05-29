//Calvin Vo
//CIS-17B
// 5-28-25

#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

// Generic package template. Indicates what gamePackage type is. In this case, it would be int.
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for string
template<>
class Package<string> {
private:
    string item;
public:
    Package(string i) : item(i) {}
    void label() {
        cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

//Specialization for holding a number of fixed items.
template<typename T, int Size>
class Box {
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
       cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};

//Ships items based on the type such as int, char, string, etc.
template<typename T>
void shipItem(const T& item) {
    cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}
int main() {

    //Greets users 
    cout << "Welcome to the Congo Smart Packaging System by Calvin Vo" << endl << "------------------------------" << endl;

    // Labels an int package.
    Package<int> intPackage(42);
    intPackage.label();
    cout << endl;

    //Labels a string package. The name of the package is being shown as the output
    Package<string> gamePackage("Best Videogames of the Decade");
    gamePackage.label();
    cout << endl;
    
    // Uses pointer for fragile items. Labels it as a double.
    double temp = 5.5;
    Package<double*> fragilePackage(&temp);
    fragilePackage.label();
    cout << endl;

    // Box is created to store and print the name of the video games listed below.
    Box<string, 2> box;
    box.addItem("Omori");
    box.addItem("Risk of Rain");
    box.printItems();
    cout << endl;

    // Ships different item types. 
    shipItem(59); // Ships int
    shipItem("Games"); // Ships char
    shipItem(9.33); // Ships double

    return 0;
}