#include<stdio.h>

struct my_struct
{
    int year;
    int mounth;
    int day;
    int hour;
    int minuts;
    int sec;
    int milisec;
    int code;
};

struct my_struct read_record_from_file(FILE *pfile, int index)
{
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(struct my_struct);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return record;
};
int main() {
    FILE *file;
     
      file = fopen("C:\\Users\\user123\\Documents\\T14D23-1-master\\datasets\\door_state_1", "rb");
     struct my_struct record1 =read_record_from_file(file,0);
    printf("%d %d" ,record1.year, record1.mounth);

}
