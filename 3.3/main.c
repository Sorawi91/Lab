#include <stdio.h>

struct student {
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
};

void upgrade( struct student *child ){

    if (child->sex == 'M' || child->sex == 'm') {
        child->gpa = child->gpa * 1.10;
        // 1.10 เท่ากับ 10%
    } else if (child->sex == 'F' || child->sex == 'f'){
        // 1.20 เท่ากับ 20%
        child->gpa = child->gpa * 1.20;
    }
}

int main() {
	struct student aboy ;

	aboy.sex = 'M' ;
	aboy.gpa = 3.00 ;

	upgrade( &aboy ) ;

	printf( "%.2f", aboy.gpa ) ;

	return 0 ;
}
