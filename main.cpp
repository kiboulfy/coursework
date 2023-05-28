#include <iostream>
#include "NeuralNetwork.h"


int main(int argc, char* argv[]) {
    // Создание экземпляра нейронной сети
    NeuralNetwork network(3);

    // Задание тренировочных данных и ожидаемых результатов
    int trainingData[4][3] = { {1, 0, 1},
                               {1, 0, 0},
                               {0, 1, 1},
                               {0, 1, 0} };
    int expectedResults[4] = {1, 1, 0, 0};
    // Обучение нейронной сети
    network.train(trainingData, expectedResults);
    // Пример использования обученной нейронной сети на новых данных
    double newData[3] = {0, 0, 1};
    double output = network.predict(newData);
    std::cout << "Output: " << output << std::endl;
    return 0;
}
