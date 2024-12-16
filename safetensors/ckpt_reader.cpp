#include <cstdint>
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

int main() {
  std::fstream ckpt_file("model.safetensors", std::ios::in | std::ios::binary);
  uint64_t header_size;
  std::string header;

  if (!ckpt_file.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }
  ckpt_file.read(reinterpret_cast<char *>(&header_size), sizeof(header_size));

  std::cout << "Header size: " << header_size << '\n';

  header.resize(header_size);
  ckpt_file.read(header.data(), header_size);

  // std::cout << "Header: " << header << '\n';

  nlohmann::json header_json = nlohmann::json::parse(header);
  for (const auto &entry : header_json.items()) {
    std::cout << entry.key() << ": " << entry.value() << '\n';
  }
}