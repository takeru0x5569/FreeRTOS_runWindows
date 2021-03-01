
#include "UserTaskDef.h"
#include <stdio.h>
//===================================================================
//
//===================================================================
int main(){
	if( 0 == TaskInit() ){
		printf("task initialize OK\n");
	}else{
		printf("task initialize ON!!!!!!\n");
	};
	 /* Start scheduler */
	UserTaskStart();

	while (1)
	{
	}
}
