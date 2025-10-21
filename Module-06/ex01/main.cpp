#include "Serializer.hpp"

int main() {
  Data data;
  data.name = "John Doe";
  data.age = 30;

  // Serialize the data pointer
  uintptr_t raw = Serializer::serialize(&data);

  // Deserialize back to a Data pointer
  Data *deserializedData = Serializer::deserialize(raw);

  // Display the deserialized data
  std::cout << "Name: " << deserializedData->name << std::endl;
  std::cout << "Age: " << deserializedData->age << std::endl;

  return 0;
}
