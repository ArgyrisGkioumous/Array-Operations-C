#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch (int *arr, int n, int target) {
	int i =0;
	while(i < n && (*(arr + i) != target)) {
		i++;
	}

	if(i<n) {
		return i;
	} else if(i==n) {
		return -1;
	}
}

int binarySearch(int *arr, int n, int target) {
	int low = 0;
	int high = n - 1;
    
	while(low <= high) {
	    int	mid = (low + high) / 2;
		if(*(arr + mid) == target) {
			return mid;
		} else if(*(arr + mid) > target) {
			high = mid - 1;
		} else low = mid + 1;
		} 
	return -1;		
}

int * sortArray(int n, int *arr) {
	int *sorted_arr = (int *) malloc (n * sizeof(int));

	if (sorted_arr == NULL) {
		return NULL;
	}
	
	
	for (int i = 0; i < n; i++) {
		(*(sorted_arr + i) = *(arr + i));
	}

	for (int i =0; i < n-1; i++) {
		for (int j =0; j < n - i - 1; j++) {
			if (*(sorted_arr + j) > *(sorted_arr + j + 1)) {
				int temp = *(sorted_arr + j);
				*(sorted_arr + j) = *(sorted_arr + j + 1);
				*(sorted_arr + j + 1) = temp;
			}
		}
	}
	return sorted_arr;
}

int * mergeArrays( int *arr1, int n) {
	int *merged_arr = (int *) malloc((2 * n) * sizeof(int));
	int *arr2 =(int *) malloc (n * sizeof(int));
	if (merged_arr == NULL || arr2 == NULL) {
		return NULL;
	}

	for (int i=0; i< n; i++) {
			*(arr2 + i) = rand() % 471 + 30;
		}
 	int *sorted_arr2 = sortArray(n, arr2);


	free(arr2);

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < n && j < n) {
		if (*(arr1 + i) <= *(sorted_arr2 + j)) {
			*(merged_arr + k) = *(arr1 + i );
			i++;
		} else {
			*(merged_arr + k) = *(sorted_arr2 + j);
			j++;
		}
		k++;
	}

	while(i < n ) {
		*(merged_arr + k) = *(arr1 + i);
		i++; 
		k++;
	}

	while(j < n) {
		*(merged_arr + k) = *(sorted_arr2 + j);
		j++;
		k++;
	}

	free(sorted_arr2);
	return merged_arr;
}

void saveToFile(const char *filename, int *arr, int size) {
	FILE *fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("Σφάλμα κατά το άνοιγμα του αρχείου!\n");
		return;
	}

	for (int i=0; i < size; i++) {
		fprintf(fp, "%d\n", *(arr+i));
	}

	fclose(fp);
	printf("Ο πίνακας αποθηκεύτηκε επιτυχώς στο %s\n", filename);
}

void readFromFile(const char *filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("Σφάλμα κατά το άνοιγμα του αρχείου!\n");
	}

	int temp_val;
	printf("\n--- Περιεχόμενα αρχείου %s ---\n", filename);

	while(fscanf(fp, "%d", &temp_val) != EOF) {
		printf("%d ", temp_val);
	}
	printf("\n");

	fclose(fp);
}

int main() { 
	int n;
	srand(time(NULL));
	printf("Δώσε το μέγεθος του πίνακα (N): ");
	scanf("%d", &n);


	int *arr1 = (int *) malloc(n * sizeof(int));

	
	if (arr1 == NULL ) {
		printf("Σφάλμα: Πρόβλημα στην δέσμευση μνήμης\n");
		return 1;
	}

	for(int i=0; i<n; i++) {
		*(arr1 + i) = rand() % 471 + 30;
	}

	int choice;
	int target;
	int pos;
	int fchoice;

	do {

	printf("Διάλεξε απο το μενού:\n");
	printf("1. Σειριακή Αναζήτηση\n");
	printf("2. Ταξινόμηση\n");
	printf("3. Δυαδική Αναζήτηση\n");
	printf("4. Συγχώνευση\n");
	printf("5. Εκτύπωση Πίνακα\n");
	printf("6. Αποθήκευση / Φόρτωση απο Αρχείο\n");
	printf("7. Έξοδος\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
			printf("Δώσε τον αριθμό που ψάχνεις: ");
			scanf("%d", &target);

			pos = linearSearch(arr1,n,target);

			if (pos != -1) {
				printf("Ο αριθμός βρέθηκε στη θέση: %d\n", pos);
			} else {
				printf("Ο αριθμός δεν βρέθηκε\n");
			}
			break;

			case 2:
			printf("Ταξινόμηση του πίνακα\n");
			int *sorted2 = sortArray(n, arr1);

			for (int i =0; i<n; i++) {
				printf("%d ", *(sorted2 +i));
			}
			printf("\n");

			printf("Η ταξινόμηση ολοκληρώθηκε\n");
			free(sorted2);
			break;

			case 3:
			printf("Δώσε τον αριθμό που ψάχνεις: ");
			scanf("%d", &target);

			
			int *sorted3 = sortArray(n, arr1);
			pos = binarySearch(sorted3, n, target);

			if (pos != -1){
				printf("Ο αριθμός βρέθηκε στην θέση: %d (στον ταξινομημένο πίνακα)\n", pos);
			} else {
				printf("Ο αριθμός δεν βρέθηκε\n");
			}
			free(sorted3);
			break;

			case 4:
			printf("Συγχώνευση πινάκων\n");
			int *sorted1 = sortArray(n, arr1); 
			int *merged = mergeArrays(sorted1, n);

			printf("Η συγχώνευση ολοκληρώθηκε. Ο νέος πίνακας είναι:\n");
			for(int i =0; i< n; i++) {
				printf("%d ", *(merged + i));
			}
			printf("\n");
			free(merged);
			free(sorted1);
			break;
			
			case 5: 
			printf("Περιεχόμενα αρχικού πίνακα:\n");
			for(int i=0; i <n; i++) {
				printf("%d ", *(arr1 + i));
			}
			printf("\n");
			break; 

			case 6:
			
			printf("1. Αποθήκευση πίνακα σε αρχείο\n");
			printf("2. Φόρτωση πίνακα απο αρχείο\n");
			printf("Διάλεξε: ");
			scanf("%d", &fchoice);

			if (fchoice == 1) {
				saveToFile("data.txt", arr1, n);
			} else if (fchoice == 2) {
				readFromFile("data.txt");
			} else {
				printf("Λανθασμένη επιλογή\n");
			}
			break; 

			case 7:
			printf("Τερματισμός προγράμματος\n");
			break;

			default:
			printf("Λανθασμένη επιλογή. Προσπαθήστε ξανά.\n");
			break;	
		}
	} while (choice != 7);
	
	free(arr1);
	return 0;
	
}
