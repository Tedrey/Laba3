#include "Pipeline.h"
#include <iostream>
#include <cstdlib> // Для system("cls")

// Инициализация статической переменной
int Pipeline::id_counter = 0;

Pipeline::Pipeline(const std::string& name, int length, int diameter, bool in_repair, int station_in_id, int station_out_id)
    : name(name), length(length), diameter(diameter), in_repair(in_repair), station_in_id(station_in_id), station_out_id(station_out_id) {
    id = ++id_counter;
}

int Pipeline::getNextId() {
    return id_counter + 1;
}

int Pipeline::getId() const {
    return id;
}
int Pipeline::getIid() const {
    return station_in_id;
}
int Pipeline::getOid() const {
    return station_out_id;
}
const std::string& Pipeline::getName() const {
    return name;
}

void Pipeline::setLength(int new_length) {
    length = new_length;
}

void Pipeline::setDiameter(int new_diameter) {
    diameter = new_diameter;
}

void Pipeline::setIsActive(bool status) {
    in_repair = status;
}
void Pipeline::setId(int id) {
    id = id;
}
double Pipeline::getLength() const { return length; }
double Pipeline::getDiameter() const { return diameter; }
bool Pipeline::isInRepair() const { return in_repair; }

void Pipeline::input() {
    // Ввод имени трубопровода
    system("cls");
    output();
    std::cout << "Enter pipeline name: ";
    std::cin >> name;
    system("cls");
    output();
    // Ввод длины с проверкой на корректность
    do {
        std::cout << "Enter the length of the " << name << " tube (must be greater than 0): ";
        std::cin >> length;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please enter a valid number.\n";
            length = -1;  // Устанавливаем некорректное значение для повторного ввода
        } else if (length <= 0) {
            std::cout << "Length must be greater than 0.\n";
        }
        system("cls");
        output();
    } while (length <= 0);  // Повторить, пока не введена корректная длина
    
    // Ввод диаметра с проверкой на корректность
    while (diameter <= 0) {
        std::cout << "Enter diameter (must be greater than 0): ";
        std::cin >> diameter;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please enter a valid number.\n";
            diameter = -1;  // Устанавливаем некорректное значение для повторного ввода
        } else if (diameter <= 0) {
            std::cout << "Diameter must be greater than 0.\n";
        }
        system("cls");
        output();
    }   // Повторить, пока не введен корректный диаметр

    // Ввод активности с проверкой
    do {
        std::cout << "Enter active status (1 for active, 0 for inactive): ";
        std::cin >> in_repair;
        if (std::cin.fail() || (in_repair != 0 && in_repair != 1)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please enter either 0 or 1.\n";
        }
        system("cls");
        output();
    } while (in_repair != 0 && in_repair != 1);  // Повторить, пока не введен корректный статус
}
void Pipeline::setStations(int in_id, int out_id, int diameter) {
    station_in_id = in_id;
    station_out_id = out_id;
    this->diameter = diameter;  // Устанавливаем диаметр для соединения
}
void Pipeline::output() const{
    std::cout<<"Tube ID:             "<<Pipeline::getId()<<"\n";
    std::cout<<"Tube name:           "<<Pipeline::getName()<<"\n";
    std::cout<<"Tube length:         "<<Pipeline::getLength()<<"\n";
    std::cout<<"Diamert of the tube: "<<Pipeline::getDiameter()<<"\n";
    std::cout<<"In repair:           " << (Pipeline::isInRepair() ? "Yes" : "No") << std::endl;
    if (Pipeline::getIid() != -1 || Pipeline::getIid() != -1) {
        std::cout<<"Connection: "<<Pipeline::getIid()<< " --> " << Pipeline::getOid()<<"\n";
    }
    std::cout<<" ---------------------- "<<std::endl;
}

void Pipeline::edit() {
    std::cout << "Editing pipeline: " << name << "\n";
    input();  // Перезаписываем данные
}
bool Pipeline::hasDiameter(int diameter) const {
    return this->diameter == diameter;
}
