#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	ma_result result;
	ma_engine engine;

	result = ma_engine_init(NULL, &engine);
	if (result != MA_SUCCESS) {
		return -1;
	}
		
	if (access(argv[1], F_OK) == 0) {
	char *ext = strrchr(argv[1], '.');
	if (!ext) {
    		puts("No file extension found.");
	} else if(strcmp(ext+1, "mp3") == 0 || 
		  strcmp(ext+1, "wav") == 0 ||
		  strcmp(ext+1, "flav") == 0 ) {
    		ma_engine_play_sound(&engine, argv[1], NULL);
                printf("Press enter to stop playing.\n");
                getchar();
	} else { puts("Unknown/Unsupported file extension"); }
	} else {
		puts("File doesn't exist.");
	}

	ma_engine_uninit(&engine);

	return 0;
}
