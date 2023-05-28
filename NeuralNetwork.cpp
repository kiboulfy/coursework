#include "NeuralNetwork.h"
#include <cmath>
#include <cstdlib>


NeuralNetwork::NeuralNetwork(int numWeights) {
    // Инициализация весов случайными значениями
    srand(1);
    for (int i = 0; i < numWeights_; i++) {
        weights_[i] = fmod(rand() % 100000000 * 0.1, 1.05);
    }
}

double NeuralNetwork::activate(double a) {
    // Функция активации: возвращает 1, если a > 0, иначе 0
    return (a > 0) ? 1 : 0;
}

double NeuralNetwork::predict(double inputs[3]) {
    double result = 0;
    for (int i = 0; i < numWeights_; i++) {
        result += weights_[i] * inputs[i];
    }
    return activate(result);
}

void NeuralNetwork::train(int data[4][3], int exp[4]) {
    const double learningRate = 0.1;
    const int numEpochs = 50;
    int dataIndex, weightIndex, epochIndex;
    double error;

    // Обучение нейронной сети
    for (epochIndex = 0; epochIndex < numEpochs; epochIndex++) {
        for (dataIndex = 0; dataIndex < 4; dataIndex++) {
            // Вычисление ошибки
            error = exp[dataIndex] - activate(predict((double*)data[dataIndex]));

            // Обновление весов
            for (weightIndex = 0; weightIndex < numWeights_; weightIndex++) {
                weights_[weightIndex] += learningRate * error * data[dataIndex][weightIndex];
            }
        }
    }
}
