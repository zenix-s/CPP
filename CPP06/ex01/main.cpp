#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Testing Serializer" << std::endl;
    std::cout << std::endl;

    Data* originalData = new Data;
    originalData->name = "Test Data";
    originalData->value = 42;
    originalData->isActive = true;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "Name: " << originalData->name << std::endl;
    std::cout << "Value: " << originalData->value << std::endl;
    std::cout << "IsActive: " << (originalData->isActive ? "true" : "false") << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserializedData = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Value: " << deserializedData->value << std::endl;
    std::cout << "IsActive: " << (deserializedData->isActive ? "true" : "false") << std::endl;
    std::cout << std::endl;

    std::cout << "Pointers equal: " << (originalData == deserializedData ? "Yes" : "No") << std::endl;

    std::cout << std::endl;

    Data* secondData = new Data;
    secondData->name = "Another Test";
    secondData->value = 123;
    secondData->isActive = false;

    std::cout << "Second test:" << std::endl;
    std::cout << "Original address: " << secondData << std::endl;

    uintptr_t serialized2 = Serializer::serialize(secondData);
    Data*     deserialized2 = Serializer::deserialize(serialized2);

    std::cout << "Deserialized address: " << deserialized2 << std::endl;
    std::cout << "Pointers equal: " << (secondData == deserialized2 ? "Yes" : "No") << std::endl;

    delete originalData;
    delete secondData;

    return 0;
}
