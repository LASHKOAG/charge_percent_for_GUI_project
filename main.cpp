#include <iostream>

using namespace std;

//значение уровня напряжения полной зарядки по документации
int32_t max_charge =12000;

//при этой величине напряжения произойдет полное отключение питания от акб
int32_t min_charge=9900;
int32_t step_charge = (max_charge - min_charge)/100;
//int b=27;
int32_t temp_value=0;

int32_t current_percent=0;

//данное значение "voltage" получаем от датчика INA
int32_t current_value=0;

int main()
{
    //for test
    current_value = 11900;

    temp_value = max_charge;

    //ищем процент заряда
    for(int8_t i = 100; i >= 0; i--){
        cout << "i = " << i << endl;
        cout << "temp_value = " << temp_value << endl;
        cout << "" << endl;

        if(current_value >= max_charge){
            //если полностью заряжен или прибор подключен сети электропитания
            current_percent = 100;
            break;
        }else if(current_value >=(temp_value-step_charge) && current_value < temp_value){
            if(current_value <= min_charge){
                current_percent = 0;
                break;
            }
            current_percent = i;
            break;
        }

        temp_value = temp_value - step_charge;
    }

    cout << "current_percent = " << current_percent << endl;

    return 0;
}
