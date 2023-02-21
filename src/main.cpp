#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>
#include "employee.h"
#include "employee_sort_strategy.h"

using namespace std;

struct EmployeeArrPrinter {

	void SetSortStrategy(EmployeeSortStrategy* const strategy) {
		sort_strategy_ = strategy;
	}
	void operator()(const std::vector<Employee>& arr) {
		assert(sort_strategy_ != nullptr);

		auto tmp{arr};
		sort_strategy_->SortEmployeeArray(tmp);

		cout << "_______________________________" << endl;
		for(const auto& empl : tmp) {
			cout << "###########" << endl;
			cout << "Employee: " << empl.name << endl;
			cout << "Age: " << empl.age << endl;
			cout << "Salary: " << empl.salary << endl;
		}
		cout << "_______________________________" << endl;
	}
private:
	EmployeeSortStrategy* sort_strategy_{nullptr};
};

int main() {

	vector<Employee> arr{{"Aron", 23, 1456.0}, {"Jack", 18, 1233.0}, {"Bob", 55, 1600.0}};

	EmployeeArrPrinter printer;

	EmployeeSortByAgeAsc age_asc_strat;
	EmployeeSortByAgeDesc age_desc_strat;
	EmployeeSortByNameAsc name_asc_strat;

	printer.SetSortStrategy(&age_asc_strat);
	printer(arr);

	printer.SetSortStrategy(&age_desc_strat);
	printer(arr);

	printer.SetSortStrategy(&name_asc_strat);
	printer(arr);

    return 0;
}
