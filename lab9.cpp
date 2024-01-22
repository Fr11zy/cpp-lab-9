#include <iostream>
//Шаблон для всех функторов

template <typename T>
class PatternFilt
{
    public:
        PatternFilt() {}

        virtual bool operator()(T element) const = 0;
};

//Функторы для проверки условий
class MultiThirdElemFilt : public PatternFilt<int>
{
    public:
        MultiThirdElemFilt(){}

        bool operator()(int element) const override
        { 
            return (abs(element)%3==0);
        }
};

class NegDoubleElemFilt : public PatternFilt<double>
{
    public:
        NegDoubleElemFilt() {}

        bool operator()(double element) const override
        {
            return (element<0);
        }
};

class BeginInWstrElemFilt : public PatternFilt<std::string>
{
    public:
        BeginInWstrElemFilt() {}

        bool operator()(std::string element) const override
        {
            return (element[0]=='w');
        }
};

class FalseBoolFilt : public PatternFilt<bool>
{
    public:
        FalseBoolFilt() {}

        bool operator()(bool element) const override
        {
            return (!element);
        }
};


//Щаблонная функция для проверки условий
template <typename T>
size_t CountFiltElements(T *array,size_t Asize,const PatternFilt<T> &filt)
{
    size_t result=0;
    for (size_t i=0;i<Asize;i++)
    {
        if (filt(array[i])) 
            result++;
    }
    return result;
}   

//main
int main()
{
    int array1[10]={1,42,66,-3,685,-76,87,876,-9,10};
    double array2[7]={1.2123,-31312.2,164.34,-535.54,455.35,-36.89,90.11};
    std::string array3[5]={"","fdxgs","nice","well played","pop"};
    bool array4[4]={true,false,true,false};

    std::cout << "Количество целых чисел, кратных трём: " << CountFiltElements(array1,10, MultiThirdElemFilt()) << std::endl;
    std::cout << "Количество отрицательных чисел с плавающей запятой: " << CountFiltElements(array2,7, NegDoubleElemFilt()) << std::endl;
    std::cout << "Количество строк, начинающихся с w: " << CountFiltElements(array3,5, BeginInWstrElemFilt()) << std::endl;
    std::cout << "Количество ложных элементов: " << CountFiltElements(array4,4, FalseBoolFilt()) << std::endl;
    return 0;
}