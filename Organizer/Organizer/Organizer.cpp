#include <iostream>
#include"Task.h"
#include"Collection_Task.h"
int main()
{
    setlocale(0, "");
    Task* task = new Task("Manikur23","Titova",12,2,2022);
    task->setDay(34);
    Collection_Task cl;
    cl.add(task);
    cl.show();
}
