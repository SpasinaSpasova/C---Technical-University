/*Task 1. Write a program that:
Defines a structure with fields: student name (first name, last name); faculty number; array of disciplines (name of discipline, grade), number of disciplines, average success. To write:
- a function that enters the data of one student (with verification of correct input data for assessment - between 2 and 6);
- a function that displays data per student;
- sorts in descending order by average success an array of students;
- a function that calculates the average success of a student;
- a function that adds a new grade for a new subject to a student;
- a function that assigns a new grade to an existing subject to a student only if it was 2 (weak);
- a function that displays the grades of all students in a given subject;
- main function, in which an array of students (student group) and their number is declared. Print an array sorted in descending order of average success. Add an appropriate menu to select all functionalities.

Task 2. Write a program that:
Defines a structure describing a customer of a mobile operator with the fields: name (first and last name), subscriber number, amount due for the current month. To define a structure describing a mobile operator, which contains an array of clients (structures) and their number. To write:
- a function that enters the data of one subscriber, with validation of the amount;
- a function that displays the data of one subscriber;
- a function that finds and returns the total amount due to all customers;
- a function that finds and returns the position of a client, with a maximum amount due;
- main function in which the variable - mobile operator is declared and the functionalities are tested.

Task 3. To define a structure describing an employee of a company with the fields: name (first and last name), position, salary by months for the current year and annual income. To define a structure describing a company, which should contain a field for the number of employees and an array of data about them.
Given the types described, compile appropriate functions to: enter data, print data, calculate the annual income of each employee and other functions that you consider appropriate.
To compile a program that displays the name and annual income of an employee with an annual salary over BGN 20,000.*/

//1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct Student {
	char name[30];
	char surname[30];
	int facultyNumber;
	int disciplineCount;
	float averageGrade;
	
	struct Discipline *disciplines;
	
} Student;

struct Discipline {
	char disciplineName[30];
	float grade;
};

struct Discipline *disConstr(char (*disNames)[30],float *grades,int disciplineCount) {
	struct Discipline *disciplines = malloc(sizeof(struct Discipline) * 30);
	char (*i)[30];
	int counter = 0,p;
	float *k;
	for(i = disNames;i < disNames + disciplineCount;i++) {
		for(p = 0;p < 30;p++) {
			if((*i)[p] == '\0') {
				disciplines[counter].disciplineName[p] = '\0';
				break;
			}
			disciplines[counter].disciplineName[p] = (*i)[p];
		}
		counter++;
	}
	counter = 0;
	for(k = grades;k < grades + disciplineCount;k++) {
		*k = *k < 2 ? 2 : *k;
		*k = *k > 6 ? 6 : *k;
		disciplines[counter].grade = *k;
		counter++;
	}
	return disciplines;
}

float findAverageGrade(Student student) {
	float sum = 0;
	int i;
	for(i = 0;i < student.disciplineCount;i++) {
		sum += student.disciplines[i].grade;
	}
	return sum / student.disciplineCount;
}

Student constr(char name[],char surname[],int facultyNumber,int disciplineCount,char (*disNames)[30],float *grades) {
	struct Discipline *disc = disConstr(disNames,grades,disciplineCount);
	
	Student foo;
	strcpy(foo.name,name);
	strcpy(foo.surname,surname);
	foo.facultyNumber = facultyNumber;
	foo.disciplineCount = disciplineCount;
	foo.disciplines = disc;
	foo.averageGrade = findAverageGrade(foo);
	return foo;
}

void printStudent(Student student) {
	printf("%s ",student.name);
	printf("%s",student.surname);
	printf("\n%d\n",student.facultyNumber);
	printf("disciplines:\n");
	struct Discipline *i;
	for(i = student.disciplines;i < student.disciplines + student.disciplineCount;i++) {
		printf("	%s - %f\n",i->disciplineName,i->grade);
	}
	printf("average grade: %f\n",student.averageGrade);
}

Student *order(Student *ptr,int studentCount) {
	int i, j;
	Student *data = malloc(sizeof(Student) * studentCount * 2);
	for(i = 0;i < studentCount;i++) {
		data[i] = *ptr;
		ptr++;
	}
    for (i = 1; i < studentCount; i++) {
        Student item = data[i];
        int ins = 0;
        for (j = i - 1; j >= 0 && ins != 1; ) {
            if (item.averageGrade > data[j].averageGrade) {
                data[j + 1] = data[j];
                j--;
                data[j + 1] = item;
            }
            else ins = 1;
        }
    }
    return data;
}

Student addDiscipline(Student student,struct Discipline newDiscipline) {
	newDiscipline.grade = newDiscipline.grade < 2 ? 2 : newDiscipline.grade;
	newDiscipline.grade = newDiscipline.grade > 6 ? 6 : newDiscipline.grade;
	realloc(student.disciplines,sizeof(struct Discipline) * (student.disciplineCount + 1));
	student.disciplines[student.disciplineCount] = newDiscipline;
	student.disciplineCount++;
	student.averageGrade = findAverageGrade(student);
	return student;
}

Student changeDisciplineGrade(Student student,float grade,int disciplinePosition) {
	if(student.disciplines[disciplinePosition].grade != 2 || grade < 2 || grade > 6) {
		return student;
	}
	student.disciplines[disciplinePosition].grade = grade;
	student.averageGrade = findAverageGrade(student);
	return student;
}

void main() {
	char arr[][30] = {"dasd","asda","asdsdsad"};
	char (*ptr)[30] = arr;
	float grades[] = {2.5,3.4,4};
	float grades1[] = {2.5,5,4};
	float grades2[] = {2.5,6,4};
	int disciplineCount = sizeof(grades) / sizeof(float);
	
	Student foo = constr("pesho","ivanov",34234,disciplineCount,ptr,grades);
	Student foo1 = constr("stamat","ivanov",34234,disciplineCount,ptr,grades1);
	Student foo2 = constr("ivan","ivanov",34234,disciplineCount,ptr,grades2);
	Student students[3] = {foo,foo1,foo2};
	
	struct Discipline newDisc = {"asdasd",2};
	students[0] = addDiscipline(students[0],newDisc);
	
	students[0] = changeDisciplineGrade(students[0],4,3);
	
	Student *orderedStudents = order(students,3);
	
	Student *i;
	for(i = orderedStudents;i < orderedStudents + 3;i++){
		printStudent(*i);
	}
}

//2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Client {
	char name[30];
	char surname[30];
	char number[10];
	float amountToPay;
} Client;

Client constr(char name[30],char surname[30],char number[10],float amountToPay) {
	amountToPay = amountToPay < 0 ? 0 : amountToPay;
	Client client = {.amountToPay = amountToPay};
	strcpy(client.name,name);
	strcpy(client.surname,surname);
	strcpy(client.number,number);
	return client;
}

void printClient(Client client) {
	printf("%s %s\n",client.name,client.surname);
	printf("number: %s\n",client.number);
	printf("amount due: %f\n",client.amountToPay);
}

float totalAmountToPay(Client *clients,int clientCount) {
	float sum = 0;
	int i;
	for(i = 0;i < clientCount;i++) {
		sum += clients[i].amountToPay;
	}
	return sum;
}

int topUserFind(Client *clients,int clientCount) {
	int maxSumPosition = 0;
	int i;
	for(i = 1;i < clientCount;i++) {
		if(clients[maxSumPosition].amountToPay < clients[i].amountToPay) {
			maxSumPosition = i;
		}
	}
	return maxSumPosition;
}

void main() {
	Client client = constr("pesho","ivanov","23123",123);
	Client client1 = constr("stamat","ivanov","242343123",43252);
	Client client2 = constr("ivan","ivanov","64563",54363);
	
	Client clients[] = {client,client1,client2};
	int clientCount = sizeof(clients) / sizeof(Client);
	
	printClient(client);
	
	printf("total amount to pay: %f\n",totalAmountToPay(clients,clientCount));
	
	printf("top client position: %d",topUserFind(clients,clientCount));
}

//3.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	char surname[30];
	char position[30];
	float* paymentsForEachMonth;
	float yearIncome;
} Employee;

Employee constr(char name[30],char surname[30],char position[30],float paymentsForEachMonth[12]) {
	Employee employee;
	strcpy(employee.name,name);
	strcpy(employee.surname,surname);
	strcpy(employee.position,position);
	int i;
	float *payments = calloc(12,sizeof(float));
	float sum = 0;
	for(i = 0;i < 12;i++) {
		if(paymentsForEachMonth[i] == '\0') {
			break;
		}
		payments[i] = paymentsForEachMonth[i];
		sum += payments[i];
	}
	employee.paymentsForEachMonth = payments;
	employee.yearIncome = sum;
	return employee;
}

void printEmployee(Employee employee) {
	printf("%s %s\n",employee.name,employee.surname);
	printf("position: %s\n",employee.position);
	printf("payments for each month: \n");
	int i;
	for(i = 0;i < 12;i++) {
		printf("%f\n",employee.paymentsForEachMonth[i]);
	}
	printf("total income: %f\n",employee.yearIncome);
}

void printRichEmployees(Employee *employees,int employeeCount) {
	int i;
	for(i = 0;i < employeeCount;i++) {
		if(employees[i].yearIncome > 20000) {
			printf("%s %s\n",employees[i].name,employees[i].surname);
			printf("total income: %f\n",employees[i].yearIncome);
		}
	}
}

Employee receivePaymentForMonth(Employee employee, float payment,int month) {
	payment = payment < 0 ? 0 : payment;
	employee.paymentsForEachMonth[month] = payment;
	employee.yearIncome += payment;
	return employee;
}

void main() {
	float payments[] = {1241,1243124,5325311,241331,'\0'};
	Employee employee = constr("pesho","peshev","shef",payments);
	float payments1[] = {1241,1,2,3,'\0'};
	Employee employee1 = constr("stamat","peshev","shef",payments1);
	float payments2[] = {1241,'\0'};
	Employee employee2 = constr("ivan","peshev","shef",payments2);
	
	Employee employees[] = {employee,employee1,employee2};
	
	employee = receivePaymentForMonth(employee,12412,5);
	
	printRichEmployees(employees,3);
}

