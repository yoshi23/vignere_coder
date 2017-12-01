//This file contains settings, file paths etc.
#ifndef CONFIG_H
#define CONFIG_H
	//Version:
	//#define DEBUG 1

	//Language properties:
	#define	ALPHABET_SIZE 26
	#define	ANSI_TO_VIGNERE_SHIFT  65
	#define ACCENTED_LETTER_THRESHOLD 128 //Windows 10 console default: for ANSI, OEM-LATIN 852

	//Paths to files:
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "kodolt.dat"
	#define VIGNERETABLE_FILE "vtabla_c++.dat"

#endif //CONFIG_H

