#ifndef TASK_H
#define TASK_H

#include "Data.hpp"

class Task {
    protected:
        Data *data;

    public:
        Task(Data *data);
        virtual void run() const = 0;
};

#endif /* TASK_H */
