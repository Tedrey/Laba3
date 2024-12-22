// FileOperations.cpp
#include "FileOperations.h"
#include <fstream>
#include <sstream>
#include "Pipeline.h"
#include <algorithm>

void savePipelines(const std::vector<Pipeline>& pipelines, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& pipeline : pipelines) {
        file << pipeline.getId() << '*' << pipeline.getName() << '*' << pipeline.getLength() << '*'
             << pipeline.getDiameter() << '*' << pipeline.isInRepair() << '*' << pipeline.getIid()<< '*' << pipeline.getOid()<< std::endl;
    }
}

void loadPipelines(std::vector<Pipeline>& pipelines, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string name;
        double length, diameter;
        bool in_repair;
        int station_in_id;  // ID входной компрессорной станции
        int station_out_id; // ID выходной компрессорной станции

        ss >> id;
        ss.ignore(); 
        
        std::getline(ss, name, '*');
        
        ss >> length;
        ss.ignore(); 

        ss >> diameter;
        ss.ignore(); 

        ss >> in_repair;
        ss.ignore(); 

        ss >> station_in_id;
        ss.ignore();

        ss>> station_out_id;
        ss.ignore();

        Pipeline p(name, length, diameter, in_repair, station_in_id, station_out_id);
        p.setId(id);
        p.id_counter = (p.id_counter > id) ? p.id_counter : id+1;
        pipelines.push_back(p);
    }
}



void saveCompressorStations(const std::vector<CompressorStation>& stations, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& station : stations) {
        file << station.getId() << '*' << station.getName() << '*' << station.getTotalShops() << '*'
             << station.getShopsInWork() << '*' << station.getEfficiency() << std::endl;
    }
}

void loadCompressorStations(std::vector<CompressorStation>& stations, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
        while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id, total_shops, shops_in_work, efficiency;
        std::string name;
        double length, diameter;
        bool in_repair;
        
        ss >> id;
        ss.ignore(); 
        
        std::getline(ss, name, '*');
        
        ss >> total_shops;
        ss.ignore(); 
        

        ss >> shops_in_work;
        ss.ignore(); 
        
        ss >> efficiency;
        
        CompressorStation s(name, total_shops, shops_in_work, efficiency);
        s.setId(id);
        s.id_counter = (s.id_counter > id) ? s.id_counter : id+1;
        stations.push_back(s);
    }
}
