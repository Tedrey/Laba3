// FileOperations.h
#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "Pipeline.h"
#include "CompressorStation.h"
#include <vector>
#include "Pipeline.h"

void savePipelines(const std::vector<Pipeline>& pipelines, const std::string& filename);
void loadPipelines(std::vector<Pipeline>& pipelines, const std::string& filename);

void saveCompressorStations(const std::vector<CompressorStation>& stations, const std::string& filename);
void loadCompressorStations(std::vector<CompressorStation>& stations, const std::string& filename);

#endif
