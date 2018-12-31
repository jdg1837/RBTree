// Reads a string for a serialized RB tree, deserializes it,
// performs some insertions, then serializes the revised tree.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RB.lab5.h"

int main()
{
	int inputBytes;
	char* inputString;
	char* outputString;
	char formatString[100];
	int insertKeys, i, key;

	scanf("%d", &inputBytes);
	inputString = (char*) malloc(inputBytes+1);
	if (!inputString) 
	{
		printf("malloc failed %d\n",__LINE__);
		exit(0);
	}

	sprintf(formatString,"%%%ds",inputBytes);
	scanf(formatString, inputString);

	STinit();
	STdeserialize(inputString);
	free(inputString);

//	STprintTree();

	scanf("%d",&insertKeys);
	for (i = 0; i < insertKeys; i++)
	{
		scanf("%d",&key);
		STinsert(key);
	}

	verifyRBproperties();

//	STprintTree();

	outputString = (char*)malloc(inputBytes + 6*insertKeys);
	outputString = STserialize(outputString);
	printf("%lu %s\n", strlen(outputString)+1, outputString);
	free(outputString);
}
