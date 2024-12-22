#include "CompressorStation.h"
#include <iostream>
#include <cstdlib> // Для system("cls")

// Инициализация статической переменной
int CompressorStation::id_counter = 0;

CompressorStation::CompressorStation(const std::string& name, int total_shops, int shops_in_work, double efficiency)
    : name(name), total_shops(total_shops), shops_in_work(shops_in_work), efficiency(efficiency) {
    static int id_counter = 0;
    id = ++id_counter;
}

int CompressorStation::getId() const {
    return id;
}

const std::string& CompressorStation::getName() const {
    return name;
}

int CompressorStation::getTotalShops() const {
    return total_shops;
}

int CompressorStation::getShopsInWork() const {
    return shops_in_work;
}

double CompressorStation::getEfficiency() const {
    return efficiency;
}

void CompressorStation::setName(const std::string& name) {
    this->name = name;
}

void CompressorStation::setTotalShops(int total_shops) {
    this->total_shops = total_shops;
}

void CompressorStation::setShopsInWork(int shops_in_work) {
    this->shops_in_work = shops_in_work;
}

void CompressorStation::setEfficiency(double efficiency) {
    this->efficiency = efficiency;
}
void CompressorStation::setId(int id) {
    this->id = id;
}
void CompressorStation::input() {
    // Запрос данных у пользователя
    system("cls");
    output();
    std::cout << "Enter name of the compressor station: ";
    std::cin >> name;
    system("cls");
    output();
    do {
        std::cout << "Enter total number of shops: ";
        std::cin >> total_shops;
        if (std::cin.fail() || total_shops <= 0) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input, total shops must be a positive number.\n";
        }
        system("cls");
        output();
    } while (total_shops <= 0);

    do {
        std::cout << "Enter number of shops in work: ";
        std::cin >> shops_in_work;
        if (std::cin.fail() || shops_in_work < 0 || shops_in_work > total_shops) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input, shops in work must be between 0 and total shops.\n";
        }
        system("cls");
        output();
    } while (shops_in_work < 0 || shops_in_work > total_shops);

    do {
        std::cout << "Enter efficiency: ";
        std::cin >> efficiency;
        if (std::cin.fail() || efficiency < 0) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input, efficiency must be a non-negative number.\n";
        }
        system("cls");
        output();
    } while (efficiency < 0);
}

void CompressorStation::output() const{
    std::cout<<"CS ID:                 "<<CompressorStation::getId()<<"\n";
    std::cout<<"CS name:               "<<CompressorStation::getName()<<"\n";
    std::cout<<"Total workshops:       "<<CompressorStation::getTotalShops()<<"\n";
    std::cout<<"Working workshops:     "<<CompressorStation::getShopsInWork()<<"\n";
    std::cout<<"Efficiency:            " <<CompressorStation::getEfficiency() << std::endl;
    std::cout<<" ---------------------- "<<std::endl;
}

void CompressorStation::edit() {
    std::cout << "Editing compressor station: " << name << "\n";
    input();  // Перезаписываем данные
}
