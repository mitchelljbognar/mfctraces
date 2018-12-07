#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, const char* argv[]) 
{
	FILE *trace_file = fopen("./trace_map.csv", "r");

        char* folder = (char*)malloc(sizeof(char)*100);
        char* file_format = (char*)malloc(sizeof(char)*100);
	
	for (int i = 0; i < 400; i++) 
	{
		fscanf(trace_file, "%s %s", folder, file_format);

		int keep_reading = 1;
		int iter = 1;
		while (keep_reading)
		{
			FILE *file;
			char* fname = (char*)malloc(sizeof(char)*100);
			strcat(fname, "./");
			strcat(fname, folder);
			strcat(fname, "/");
			strcat(fname, file_format);
			strcat(fname, "_");

			char iter_string[10];
			sprintf(iter_string, "%d", iter);
			strcat(fname, iter_string);
			
			printf("%s \n", fname);	
 			
			//if ((access ( fname, F_OK ) ) != -1)
			file = fopen(fname, "r");
			if(file != NULL)
			{
    				
				char* page_as_string = (char*)malloc(sizeof(char)*8192);
				fscanf(file, "%8192c", page_as_string);
				
				printf("%c  \n", page_as_string[3]);
				iter++;
				fclose(file);
				for (int m = 0; m < 8192; m++) {
					page_as_string = 0;
				}
			}
			else {
				keep_reading = 0;
			}
			free(fname);
		}

		for(int k = 0; k < 100; k++) {
			folder[k] = 0;
			file_format[k] = 0;
		}
	}	
	free(file_format);
	free(folder);
}
