using COMPANY

/* #region   */
set dateformat dmy

create table EMPLOYEE
(
  Fname		varchar(20),
  Minit		varchar(1),
  Lname 	varchar(20),
  Ssn		varchar(9),
  Bdate		date,
  Addr		varchar(20),
  Sex		varchar(1),
  Salary	varchar(10),
  Super_ssn	varchar(9),
  Dno		varchar(3)

  add constraint EMPLOYEE_PK primary key (Ssn)
)

create table DEPARTMENT
(
	Dname		varchar(20),
	Dnumber		varchar(3),
	Mgr_ssn		varchar(9),
	Mgr_start_date	date

	add constraint DEPARTMENT_PK primary key (Dnumber)
)

create table DEPT_LOCATIONS
(
	Dnumber		varchar(3),
	Dlocation	varchar(15)

	add constraint DEPT_LOCATIONS_PK primary key (Dnumber, Dlocation)
)

create table PROJECT
(
  Pname		varchar(20),
  Pnumber		varchar(3),
  Plocation	varchar(15),
  Dnum		varchar(3)

  add constraint PROJECT_PK primary key (Pnumber)
)

create table WORKS_ON
(
  Essn		varchar(9),
  Pno		varchar(3),
  Hours		varchar(3)

add constraint WORKS_ON_PK primary key (Essn, Pno)
)

create table DEPENDENT
(
  Essn    varchar(9),
  Dependent_name varchar(20),
  Sex     varchar(1),
  Bdate   date,
  Relationship varchar(10)
)
/* #endregion */

/* #region   */
-- Query

-- a) List the names of all employees in department 5 who work more than 10 hours per week on the Product X project.
select e.Fname, e.Lname
from EMPLOYEE e,
  WORKS_ON w,
  PROJECT p
where e.Ssn = w.Essn
  and w.Pno = p.Pnumber
  and p.Pname = 'Product X'
  and w.Hours > 10
  and e.Dno = 5

-- b) List the names of all employees who have a dependent with the same first name as themselves.
select e.Fname, e.Lname
from EMPLOYEE e,
  DEPENDENT d
where e.Ssn = d.Essn
  and e.Fname = d.Dependent_name

-- c) List the names of employees who are directly supervised by Franklin Wong.
select e.Fname, e.Lname
from EMPLOYEE e,
  EMPLOYEE e2
where e.Super_ssn = e2.Ssn
  and e2.Fname = 'Franklin'
  and e2.Lname = 'Wong'

-- d) List the names of employees who work on every project.
select e.Fname, e.Lname
from EMPLOYEE e
where not exists (select *
                  from PROJECT p
                  where not exists (select *
                                    from WORKS_ON w
                                    where w.Essn = e.Ssn
                                    and w.Pno = p.Pnumber))
                                    
-- e) List the names of employees who do not work on any project.
select e.Fname, e.Lname
from EMPLOYEE e
where not exists (select *
                  from WORKS_ON w
                  where w.Essn = e.Ssn)

-- f) List the names and addresses of employees who work on at least one project located in Houston but whose department has no location in Houston.
select e.Fname, e.Lname, e.Addr
from EMPLOYEE e,
  WORKS_ON w,
  PROJECT p,
  DEPT_LOCATIONS dl
where e.Ssn = w.Essn
  and w.Pno = p.Pnumber
  and p.Plocation = 'Houston'
  and e.Dno = dl.Dnumber
  and dl.Dlocation != 'Houston'

-- g) List the names of department managers who have no dependents
select e.Fname, e.Lname
from EMPLOYEE e
where not exists (select *
                  from DEPENDENT d
                  where d.Essn = e.Ssn)
  and e.Ssn in (select d.Mgr_ssn
                from DEPARTMENT d)

-- h) A view that has the department name, manager name, and manager salary for every department
create view DEPT_MGR_SALARY
as select d.Dname, e.Fname, e.Lname, e.Salary
from DEPARTMENT d,
  EMPLOYEE e
where d.Mgr_ssn = e.Ssn

-- i) A view that has the employee name, supervisor name, and employee salary for each employee who works in the ‘Research’ department
create view EMPLOYEE_SUPERVISOR_SALARY
as select e.Fname, e.Lname, e2.Fname, e2.Lname, e.Salary
from EMPLOYEE e,
  EMPLOYEE e2
where e.Super_ssn = e2.Ssn
  and e.Dno = 5

-- j) A view that has the project name, controlling department name, number of employees, and total hours worked per week on the project for each project
create view PROJECT_INFO
as select p.Pname, d.Dname, count(w.Essn), sum(w.Hours)
from PROJECT p,
  DEPARTMENT d,
  WORKS_ON w
where p.Dnum = d.Dnumber
  and p.Pnumber = w.Pno

-- k) A view that has the project name, controlling department name, number of employees, and total hours worked per week on the project for each project with more than one employee working on it
create view PROJECT_INFO
as select p.Pname, d.Dname, count(w.Essn), sum(w.Hours)
from PROJECT p,
  DEPARTMENT d,
  WORKS_ON w
where p.Dnum = d.Dnumber
  and p.Pnumber = w.Pno
/* #endregion */





using GRADEBOOK

/* #region   */
create table CATALOUGE
(
  Cno    varchar(3),
  Ctitle varchar(20),
  
  add constraint CATALOUGE_PK primary key (Cno)
)

create table STUDENTS
(
  Ssn   varchar(9),
  Fname  varchar(20),
  Minit  varchar(1),
  Lname  varchar(20),
  
  add constraint STUDENTS_PK primary key (Ssn)
)

create table COURSES
(
  Term    varchar(20),
  Sec_no  varchar(20),
  Cno     varchar(3),
  A       int,
  B       int,
  C       int,
  D       int,
  
  add constraint COURSES_PK primary key (Term, Sec_no)
)

create table ENROLLS
(
  Ssn     varchar(9),
  Term    varchar(20),
  Sec_no  varchar(20),
  
  add constraint ENROLLS_PK primary key (Ssn, Term, Sec_no)
)
/* #endregion */


/* #region   */
-- Query

-- a) Retrieve the names of students enrolled in the Automata class during the fall 2009 term.
select Ssn, Fname, Lname
from STUDENTS
where Ssn in (select Ssn
              from ENROLLS
              where Term = 'Fall 2009'
                and Sec_no = '1')

-- b) Retrieve the Ssn values of students who have enrolled in CSc226 and CSc227.
select Ssn
from ENROLLS
where Cno = 'CSc226'
  and Cno = 'CSc227'

-- c) Retrieve the Ssn values of students who have enrolled in CSc226 or CSc227.
select Ssn
from ENROLLS
where Cno = 'CSc226'
  or Cno = 'CSc227'

-- d) Retrieve the names of students who have not enrolled in any class.
select Ssn, Fname, Lname
from STUDENTS
where Ssn not in (select Ssn
                  from ENROLLS)

-- e) Retrieve the names of students who have enrolled in all courses in the CATALOG table.
select Ssn, Fname, Lname
from STUDENTS
where Ssn in (select Ssn
              from ENROLLS
              where Cno in (select Cno
                            from CATALOUGE))
/* #endregion */





using MAILORDER

/* #region   */
create table PARTS
(
  Pno     varchar(3),
  Pname		varchar(20),
  Qoh     varchar(3),
  Price   varchar(5),
  Olevel  varchar(3),
  
  add constraint PARTS_PK primary key (Pno)
)

create table CUSTOMERS
(
  Cno     varchar(3),
  Cname		varchar(20),
  Street  varchar(20),
  Zip     varchar(5),
  Phone   varchar(10),
  
  add constraint CUSTOMERS_PK primary key (Cno)
)

create table EMPLOYEES
(
  Eno     varchar(3),
  Ename		varchar(20),
  Zip     varchar(5),
  Hdate   date,
  
  add constraint EMPLOYEES_PK primary key (Eno)
)

create table ZIP_CODES
(
  Zip     varchar(5),
  City    varchar(20),
  
  add constraint ZIP_CODES_PK primary key (Zip)
)

create table ORDERS
(
  Ono     varchar(3),
  Cno     varchar(3),
  Eno     varchar(3),
  Received date,
  Shipped  date,
  
  add constraint ORDERS_PK primary key (Ono)
)

create table ODETAILS
(
  Ono     varchar(3),
  Pno     varchar(3),
  Qty     varchar(3),
  
  add constraint ODETAILS_PK primary key (Ono, Pno)
)
/* #endregion */


/* #region   */
-- Query

-- a) Retrieve the names of parts that cost less than $20.00.
select Pname
from PARTS
where Price < 20

-- b) Retrieve the names and cities of employees who have taken orders for parts costing more than $50.00.
select Ename, City
from EMPLOYEES e,
  ZIP_CODES z,
  ORDERS o,
  ODETAILS od,
  PARTS p
where e.Zip = z.Zip
  and e.Eno = o.Eno
  and o.Ono = od.Ono
  and od.Pno = p.Pno
  and p.Price > 50

-- c) Retrieve the pairs of customer number values of customers who live in the same ZIP code.
select c1.Cno, c2.Cno
from CUSTOMERS c1, CUSTOMERS c2
where c1.Zip = c2.Zip
  and c1.Cno != c2.Cno

-- d) Retrieve the names of customers who have ordered parts from employees living in Wichita.
select c.Cname
from CUSTOMERS c,
  ORDERS o,
  EMPLOYEES e,
  ZIP_CODES z
where c.Cno = o.Cno
  and o.Eno = e.Eno
  and e.Zip = z.Zip
  and z.City = 'Wichita'

-- e) Retrieve the names of customers who have ordered parts costing less than $20.00.
select c.Cname
from CUSTOMERS c,
  ORDERS o,
  ODETAILS od,
  PARTS p
where c.Cno = o.Cno
  and o.Ono = od.Ono
  and od.Pno = p.Pno
  and p.Price < 20

-- f) Retrieve the names of customers who have not placed an order.
select c.Cname
from CUSTOMERS c
where not exists (select *
                  from ORDERS o
                  where o.Cno = c.Cno)

-- g) Retrieve the names of customers who have placed exactly two orders
select c.Cname
from CUSTOMERS c
where c.Cno in (select o.Cno
                from ORDERS o
                group by o.Cno
                having count(*) = 2)
/* #endregion */
  



using SUPPLYCHAIN

/* #region   */
create table SUPPLIER
(
  Sno     varchar(9),
  Sname		varchar(20)
  
  add constraint SUPPLIER_PK primary key (Sno)
)

create table PART
(
  Pno     varchar(9),
  Pname		varchar(20)
  
  add constraint PART_PK primary key (Pno)
)

create table PROJECT
(
  Jno     varchar(9),
  Jname		varchar(20)
  
  add constraint PROJECT_PK primary key (Jno)
)

create table SUPPLY
(
  Sno     varchar(9),
  Pno     varchar(9),
  Jno     varchar(9),
  
  add constraint SUPPLY_PK primary key (Sno, Pno)
)
/* #endregion */


/* #region   */
-- Query

-- a) Retrieve the part numbers that are supplied to exactly two projects.
select Pno
from SUPPLY
group by Pno
having count(distinct Jno) = 2

-- b) Retrieve the names of suppliers who supply more than two parts to project ‘J1’.
select Sname
from SUPPLIER
where Sno in (select Sno
              from SUPPLY
              where Jno = 'J1'
              group by Sno
              having count(distinct Pno) > 2)

-- c) Retrieve the part numbers that are supplied by every supplier.
select Pno
from SUPPLY
group by Pno
having count(distinct Sno) = (select count(Sno)
                              from SUPPLIER)

-- d) Retrieve the project names that are supplied by supplier ‘S1’ only.
select Jname
from PROJECT
where Jno in (select Jno
              from SUPPLY
              where Sno = 'S1'
              group by Jno
              having count(distinct Pno) = (select count(Pno)
                                            from PART))

-- e) Retrieve the names of suppliers who supply at least two different parts each to at least two different projects.
select Sname
from SUPPLIER
where Sno in (select Sno
              from SUPPLY
              group by Sno
              having count(distinct Pno) >= 2
                and count(distinct Jno) >= 2)
/* #endregion */





using STUDENT_MGT

/* #region   */
create table STUDENT
(
  Sname   varchar(20),
  Student_number     varchar(9),
  Class   varchar(2),
  Major   varchar(20),
)

create table COURSE
(
  Course_name   varchar(20),
  Course_number     varchar(9),
  Credit_hours     varchar(2),
  Department   varchar(20),
)

create table SECTION
(
  Section_identifier  varchar(9),
  Course_number       varchar(9),
  Semester    varchar(20),
  Year        varchar(4),
  Instructor  varchar(20),
)

create table GRADE_REPORT
(
  Student_number  varchar(9),
  Section_identifier  varchar(9),
  Grade   varchar(2),
)

create table PREQUISITE
(
  Course_number                varchar(9),
  Prerequisite_course_number   varchar(9),
)
/* #endregion */


/* #region   */
-- Query

-- a) Retrieve the names of all senior students majoring in ‘cs’ (computer science).
select Student_name
from STUDENT
where Class = 'senior'
  and Major = 'cs'

-- b) Retrieve the names of all courses taught by Professor King in 2007 and 2008.
select Course_name
from COURSE
where Course_number in (select Course_number
                        from SECTION
                        where Instructor = 'King'
                          and Year in ('2007', '2008'))

-- c) For each section taught by Professor King, retrieve the course number, semester, year, and number of students who took the section.
select Course_number, Semester, Year, count(Student_number)
from SECTION
where Instructor = 'King'
group by Course_number, Semester, Year

-- d) Retrieve the name and transcript of each senior student (Class = 4) majoring in CS.
-- A transcript includes course name, course number, credit hours, semester, year, and grade
-- for each course completed by the student.
select Student_name, Course_name, Course_number, Credit_hours, Semester, Year, Grade
from STUDENT
  join GRADE_REPORT on Student_number = Student_number
  join SECTION on Section_identifier = Section_identifier
  join COURSE on Course_number = Course_number
where Class = 'senior'
  and Major = 'cs'

-- e) Retrieve the names and major departments of all straight-A students (students who have a grade of A in all their courses).
select Student_name, Major
from STUDENT
where Student_number in (select Student_number
                         from GRADE_REPORT
                         group by Student_number
                         having count(Grade) = (select count(Grade)
                                                from GRADE_REPORT
                                                where Grade = 'A'))

-- f) Retrieve the names and major departments of all students who do not have a grade of A in any of their courses.
select Student_name, Major
from STUDENT
where Student_number not in (select Student_number
                             from GRADE_REPORT
                             where Grade = 'A')
/* #endregion */