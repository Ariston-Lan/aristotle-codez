#pragma once

void stat_tool();

template <typename T>
T getMax(T num1, T num2, T num3){
    if(num1 > num2 && num1 > num3){
        return num1;
    }
    else if(num2 > num1 && num2 > num3){
        return num2;
    }
    else if(num3 > num1 && num3 > num2){
        return num3;
    }
    return 0;
}

template <typename T>
T getMin(T num1, T num2, T num3){
    if(num1 < num2 && num1 < num3){
        return num1;
    }
    if(num2 < num1 && num2 < num3){
        return num2;
    }
    if(num3 < num1 && num3 < num2){
        return num3;
    }
    return 0;
}


template <typename T>
T getAverage(T num1, T num2, T num3){
    return (num1+num2+num3)/3;
}

template <int N, typename T>
T scaleValue(T value){
    return value*N;
}