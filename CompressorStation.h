#ifndef COMPRESSORSTATION_H
#define COMPRESSORSTATION_H

#include <string>

class CompressorStation {
private:
    int id;
    std::string name;
    int total_shops;
    int shops_in_work;
    double efficiency;
    
public:
    CompressorStation(const std::string& name, int total_shops, int shops_in_work, double efficiency);
    static int id_counter;
    void setId(int id);
    int getId() const;
    const std::string& getName() const;
    int getTotalShops() const;
    int getShopsInWork() const;
    double getEfficiency() const;

    void setName(const std::string& name);
    void setTotalShops(int total_shops);
    void setShopsInWork(int shops_in_work);
    void setEfficiency(double efficiency);
    
    void input();  // Метод для ввода данных
    void output() const;  // Метод для вывода данных
    void edit();  // Метод для редактирования
};

#endif
