// netease_music_cache_decode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
int decode(char *inputname);

int main(int argc, char *argv[])
{
	if(argv[1] == NULL)
	{
		return 0;
	}
	decode(argv[1]);
	return 0;
}

int decode(char *inputname)
{
	FILE *input_file, *output_file = NULL;
	input_file = fopen(inputname, "rb");
	output_file = fopen("complete.mp3", "wb");
	if (input_file == NULL || output_file == NULL)
	{
		return 1;
	}
	long file_size = 0;
	fseek(input_file, 0, SEEK_END);
	file_size = ftell(input_file);
	fseek(input_file, 0, SEEK_SET);
	unsigned char *buffer = (unsigned char *)calloc(sizeof(char), file_size);
	fread(buffer, sizeof(char), file_size, input_file);
	for (int i = 0; i<file_size; i++)
	{
		buffer[i] = buffer[i] ^ 0xa3;
	}
	fwrite(buffer, sizeof(char), file_size, output_file);
	fclose(input_file);
	fclose(output_file);
	return 0;
}
