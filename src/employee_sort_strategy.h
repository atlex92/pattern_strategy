#pragma once

#include <vector>
#include <algorithm>
#include "employee.h"

struct EmployeeSortStrategy {
    virtual ~EmployeeSortStrategy() = default;
    virtual void SortEmployeeArray(std::vector<Employee>& arr) = 0;
};

struct EmployeeSortByNameAsc : EmployeeSortStrategy {
    void SortEmployeeArray(std::vector<Employee>& arr) override {
        std::sort(arr.begin(), arr.end(), [](const Employee& left, const Employee& right){return left.name < right.name;});
    }
};

struct EmployeeSortByAgeAsc : EmployeeSortStrategy {
    void SortEmployeeArray(std::vector<Employee>& arr) override {
        std::sort(arr.begin(), arr.end(), [](const Employee& left, const Employee& right){return left.age < right.age;});
    }
};

struct EmployeeSortByAgeDesc : EmployeeSortStrategy {
    void SortEmployeeArray(std::vector<Employee>& arr) override {
        std::sort(arr.begin(), arr.end(), [](const Employee& left, const Employee& right){return left.age > right.age;});
    }
};
