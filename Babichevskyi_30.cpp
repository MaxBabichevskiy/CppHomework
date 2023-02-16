//Babichevskyi 030

#include <iostream>
#include <vector>
#include <algorithm>

struct Car {
    std::string name;
    int year;
    double engineSize;
    double price;
};

// Функторы для сравнения машин по разным параметрам
struct CompareByName {
    bool operator()(const Car& a, const Car& b) const {
        return a.name < b.name;
    }
};

struct CompareByYear {
    bool operator()(const Car& a, const Car& b) const {
        return a.year < b.year;
    }
};

struct CompareByEngineSize {
    bool operator()(const Car& a, const Car& b) const {
        return a.engineSize < b.engineSize;
    }
};

struct CompareByPrice {
    bool operator()(const Car& a, const Car& b) const {
        return a.price < b.price;
    }
};

int main() {
    std::vector<Car> cars;

    // Лямбда-функция для добавления машины в вектор
    auto addCar = [&cars]() {
        Car car;
        std::cout << "Enter car name: ";
        std::cin >> car.name;
        std::cout << "Enter year: ";
        std::cin >> car.year;
        std::cout << "Enter engine size: ";
        std::cin >> car.engineSize;
        std::cout << "Enter price: ";
        std::cin >> car.price;
        cars.push_back(car);
        std::cout << "Car added successfully." << std::endl;
    };

    // Лямбда-функция для удаления машины из вектора
    auto removeCar = [&cars]() {
        std::cout << "Enter car name to remove: ";
        std::string nameToRemove;
        std::cin >> nameToRemove;
        auto it = std::remove_if(cars.begin(), cars.end(),
            [nameToRemove](const Car& car) { return car.name == nameToRemove; });
        if (it != cars.end()) {
            cars.erase(it, cars.end());
            std::cout << "Car removed successfully." << std::endl;
        }
        else {
            std::cout << "Car not found." << std::endl;
        }
    };

    // Лямбда-функция для вывода машин на экран
    auto printCars = [&cars]() {
        for (const auto& car : cars) {
            std::cout << car.name << ", " << car.year << ", "
                << car.engineSize << "L, $" << car.price << std::endl;
        }
    };

    // Меню для выбора действия
    int choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add car" << std::endl;
        std::cout << "2. Remove car" << std::endl;
        std::cout << "3. View cars" << std::endl;
        std::cout << "4. Sort cars by name" << std::endl;
        std::cout << "5. Sort cars by year" << std::endl;
        std::cout << "6. Sort cars by engine size" << std::endl;
        std::cout << "7. Sort cars by price" << std::endl;
        std::cout << "8. Search cars by name" << std::endl;
        std::cout << "9. Search cars by year" << std::endl;
        std::cout << "10. Search cars by engine size" << std::endl;
        std::cout << "11. Search cars by price" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            addCar();
            break;
        case 2:
            removeCar();
            break;
        case 3:
            printCars();
            break;
        case 4:
            std::sort(cars.begin(), cars.end(), CompareByName());
            std::cout << "Cars sorted by name." << std::endl;
            break;
        case 5:
            std::sort(cars.begin(), cars.end(), CompareByYear());
            std::cout << "Cars sorted by year." << std::endl;
            break;
        case 6:
            std::sort(cars.begin(), cars.end(), CompareByEngineSize());
            std::cout << "Cars sorted by engine size." << std::endl;
            break;
        case 7:
            std::sort(cars.begin(), cars.end(), CompareByPrice());
            std::cout << "Cars sorted by price." << std::endl;
            break;
        case 8:
        {
            std::cout << "Enter car name to search for: ";
            std::string nameToSearch;
            std::cin >> nameToSearch;
            auto it = std::find_if(cars.begin(), cars.end(),
                [nameToSearch](const Car& car) { return car.name == nameToSearch; });
            if (it != cars.end()) {
                std::cout << it->name << ", " << it->year << ", "
                    << it->engineSize << "L, $" << it->price << std::endl;
            }
            else {
                std::cout << "Car not found." << std::endl;
            }
            break;
        }
        case 9:
        {
            std::cout << "Enter year to search for: ";
            int yearToSearch;
            std::cin >> yearToSearch;
            auto it = std::find_if(cars.begin(), cars.end(),
                [yearToSearch](const Car& car) { return car.year == yearToSearch; });
            if (it != cars.end()) {
                std::cout << it->name << ", " << it->year << ", "
                    << it->engineSize << "L, $" << it->price << std::endl;
            }
            else {
                std::cout << "Car not found." << std::endl;
            }
            break;
        }
        case 10:
        {
            std::cout << "Enter engine size to search for: ";
            double engineSizeToSearch;
            std::cin >> engineSizeToSearch;
            auto it = std::find_if(cars.begin(), cars.end(),
                [engineSizeToSearch](const Car& car) { return car.engineSize == engineSizeToSearch; });
            if (it != cars.end()) {
                std::cout << it->name << ", " << it->year << ", "
                    << it->engineSize << "L, $" << it->price << std::endl;
            }
            else {
                std::cout << "Car not found." << std::endl;
            }
            break;
        }
        case 11:
        {
            std::cout << "Enter price to search for: ";
            double priceToSearch;
            std::cin >> priceToSearch;
            auto it = std::find_if(cars.begin(), cars.end(),
                [priceToSearch](const Car& car) { return car.price == priceToSearch; });
            if (it != cars.end()) {
                std::cout << it->name << ", " << it->year << ", "
                    << it->engineSize << "L, $" << it->price << std::endl;
            }
            else {
                std::cout << "Car not found." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }

    return 0;

}
