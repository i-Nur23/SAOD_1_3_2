#include <iostream>

using namespace std;

const int maxSize = 10;

struct ArrayList
{
    int Count;
    int array[maxSize];
};

void InitList(ArrayList *& list)
{
    list->Count = 0;
    for (int i = 0; i < maxSize; i++)
    {
        list->array[i] = 0;
    }
}

int CheckedInput(int begin, int end) // Ввод целочисленного значения с проверкой
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        if (choice < begin || choice > end)
        {
            cout << "Вводите данные корректно: ";
            continue;
        }
        break;
    }
    return choice;
}

int CheckedInput() // Ввод целочисленного значения с проверкой
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        break;
    }
    return choice;
}

bool isEmpty(ArrayList*& myList) // проверка списка на пустоту
{
    if (myList->Count == 0)
    {
        return true;
    }
    return false;
}

bool isFull(ArrayList* myList) // проверка списка на полноту
{
    if (myList->Count == maxSize)
    {
        return true;
    }
    return false;
}

void PrintList(ArrayList* myList) // вывод списка
{
    for (int i = 0; i < myList->Count; i++)
    {
        cout << myList->array[i] << " ";
    }
}

int Search(ArrayList* myList, int number) // поиск значения в списке 
{
    for (int i = 0; i < (myList->Count); i++)
    {
        if (myList->array[i] == number)
        {
            return i;
        }
    }
    return -1;
}

void Add(ArrayList*& myList, int number) // добавление элемента в упорядоченный список
{
    if (isEmpty(myList))
    {
        myList->array[0] = number;
    }
    else if (number > myList->array[(myList->Count) - 1])
    {
        myList->array[myList->Count] = number;
    }
    else
    {
        int index = 0;
        while (index + 1 <= myList->Count)
        {
            if (number < myList->array[index])
            {
                int indToMove = myList->Count;
                while (indToMove > index)
                {
                    myList->array[indToMove] = myList->array[indToMove - 1];
                    indToMove --;
                }
                myList->array[index] = number;
                break;
            }
            index ++;
        }
    }
    (myList->Count) ++;
}

void Delete(ArrayList* myList, int index) // удаление элемента списка по индексу
{
    for (int i = index; i < (myList->Count) - 1; i++)
    {
        myList->array[i] = myList->array[i + 1];
    }
    myList->array[(myList->Count) - 1] = 0;
    (myList->Count)--;
}

void CallMenu(ArrayList*& myList) // вызов меню
{
    bool work = true;
    int choice;
    while (work)
    {
        cout << "Выбор действия:\n1 - Вывод списка\n2 - Поиск элемента с заданной информационной частью\n3 - Добавление элемента\n4 - Удаление заданного элемента\n5 - Завершить работу\n";
        cout << "Действие: "; choice = CheckedInput(1, 5);
        switch (choice)
        {
        case 1:
            if (isEmpty(myList))
            {
                cout << "Список пустой.";
            }
            else
            {
                cout << "Список: "; PrintList(myList);
            }
            cout << "\n\n";
            break;
        case 2:
            int elemsIndex;
            cout << "Введите информационную часть, индекс которой надо найти: "; elemsIndex = Search(myList,CheckedInput());
            if (elemsIndex == -1)
            {
                cout << "Такого элемента в списке нет.";
            }
            else
            {
                cout << "Элемент " << elemsIndex << "-ый по списку.";
            }
            cout << "\n\n";
            break;
        case 3:
            if (isFull(myList))
            {
                cout << "Список заполнен";
                break;
            }
            cout << "Введите число, которое хотите добавить: "; Add(myList, CheckedInput());
            cout << "\n\n";
            break;
        case 4:
            int indexToDelete;
            if (isEmpty(myList))
            {
                cout << "Список пуст";
                break;
            }
            cout << "Введите индекс: "; indexToDelete = CheckedInput(0,(myList->Count)-1);
            Delete(myList, indexToDelete);
            cout << "\n\n";
            break;
        case 5:
            work = false;
            break;
        default:
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ArrayList* myList = new ArrayList;
    InitList(myList);
    CallMenu(myList);
    delete myList;
    return 0;
}