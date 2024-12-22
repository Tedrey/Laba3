#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>

class Pipeline {
private:
    
    int id;
    std::string name;
    int length;
    int diameter;
    bool in_repair;
    int station_in_id;  // ID входной компрессорной станции
    int station_out_id; // ID выходной компрессорной станции

public:
    Pipeline(const std::string& name, int length, int diameter, bool in_repair, int station_in_id, int station_out_id);
    static int id_counter;  // Статическая переменная для уникальных ID
    static int getNextId(); // Возвращает следующий ID
    int getId() const;
    const std::string& getName() const;
    int getIid() const;
    int getOid() const;
    double getLength() const;
    double getDiameter() const;
    bool isInRepair() const;
    void setId(int id);
    void setStations(int in_id, int out_id, int diameter);
    void setLength(int new_length);
    void setDiameter(int new_diameter);
    void setIsActive(bool status);
    bool hasDiameter(int diameter) const;
    void input();
    void output() const;
    void edit();
};

#endif // PIPELINE_H
