#include <stdio.h>
#include <iostream>
#include <string.h>
#include "json/json.h"
using namespace std;
using namespace Json;
int main(int argc, char *argv[])
{
	const char json[]="{\"a\":\"1\",\"b\":\"2\"}";
	CharReaderBuilder newread;
	//CharReader *read = newread.newCharReader();
	CharReader *read(newread.newCharReader());
	Value root;
	
	if (false == read->parse(json, json+strlen(json), &root, NULL)){
		printf("parser false\n");
	}
	printf("%s\n",root["a"].asCString());

	Value write_root;
	write_root["francis"]=1;
	write_root["age"]["a"]=18;
	write_root["age"]["b"]=1;

	StreamWriterBuilder build;
	StreamWriter *write=build.newStreamWriter();
	ostringstream os;
	write->write(write_root, &os);
	printf("%s",os.str().c_str());
	delete read;
	delete write;

	return 0;
}
