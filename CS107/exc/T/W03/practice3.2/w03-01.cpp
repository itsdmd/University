#include "src/student.h"

int main() {
	const char *name_s2 = "Jerry";
	
	Student *s1 = new Student();
	Student s2(name_s2, 0, 0);
	Student s3 = s2;
	
	delete s1;
	
	return 0;
}