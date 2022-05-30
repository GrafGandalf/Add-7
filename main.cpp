//
//  main.cpp
//  
//
#include <iostream>
#include <locale>
#include <vector>
#include <fstream>
#include <math.h>


bool Prost(int a)
{
    int count=0;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0)
        {
            count++;
        }
    }
    if (count==0) return true;
    else return false;
        
}
bool P15(int a)
{
    int sum=0;
    while (a!=0)
        {
            sum += a%10;
            a /= 10;
        }
    if (sum==15) return true;
    else return false;
}

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    std::vector<int> Mass(10000, 0); int a=0;
    
    std::ifstream file("/Users/enil/Desktop/AddGotov/Add-5/input.txt");
    
    file >> a;
    
    for (int i=0; i<a; i++)
    {
        file >> Mass[i];
    }
    
    file.close();
    
    
    int in=0; int ou=0;
    
    for (int i=0; i<a; i++)
    {
        if (Prost(Mass[i])==true)
        {
            Mass[i]=-2147483647;
            in++;
        }
    }
    
    for (int i=0; i<a; i++)
    {
        if (Mass[i]==-2147483647)
        {
           
            for (int j=i; j<a-1; j++)
            {
                Mass[j]=Mass[j+1];
            }
            if (Mass[i]==-2147483647) i--;
        }
    }
    
    a-=in; // Удаление чисел
    
    
    for (int i=0; i<a; i++)
    {
        if ((Prost(Mass[i])==false)&&(P15(Mass[i])==true))
        {
            ou++;
            for (int j=a-1; j>=i; j--)
            {
                Mass[j+1]=Mass[j];
            }
            i++;
        }
    }
    
    a+=ou; //Дублирование
    
    
    std::ofstream file1("/Users/enil/Desktop/AddGotov/Add-5/output.txt", std::ios::out);
    
    for (int i=0; i<a; i++)
    {
        file1 << Mass[i] << " ";
    }
    
    file.close();
    
    
    return 0;
}
