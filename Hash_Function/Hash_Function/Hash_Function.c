#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// These are encoded IDs, different from actual ones
#define NUM_STUDENTS	49
static long students_id[NUM_STUDENTS] = {
  46104020, 46104024, 46104098, 46104166, 46104178,
  46104193, 46104262, 46104290, 46104295, 46104301,
  46104321, 46104336, 46104372, 46104382,
  47037217, 47104017, 47104049, 47104081, 47104086,
  47104129, 47104132, 47104189, 47104214, 47104277,
  47104307, 47104313, 47104449, 47104463, 47110170,
  47110576, 47113099, 47113964, 47114727, 47117785,
  47118653, 47114989, 47115012,
  49104004, 49104051, 49104090, 49104117, 49104176,
  49104184, 49104293, 49104325, 49104339, 49104404,
  49104406, 49118005,
};


/////////////////////////////////////////////////////////////////////
// if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////
void buildhash(long* key, int last);
int hashft(long students_id, int last);
int hashft1(long students_id, int last);
int hashft2(long students_id, int last);
int collision(long students_id, int last, int j);

void buildhash(long* key, int last) {
    int i = 0;
    int j = 0;
    int key_index;
    int total_collision = 0;

    while(i < NUM_STUDENTS) {
        key_index = hashft1(students_id[i], last);
        printf("key_index by hashft1 : %d\n", key_index);

        //conflicted
        printf("result by hashft2 : %d\n", hashft2(students_id[i], last));
        while(key[key_index] != 0) {
            j++;
            key_index = collision(students_id[i], last, j);
        }

        printf("key_index : %d\n", key_index);
        key[key_index] = students_id[i];

        printf("count : %d\n", j);
        printf("\n");
        total_collision = total_collision + j;
        j = 0;
        i++;
    }
    printf("total_collision : %d\n\n", total_collision);

    for(int j = 0; j < NUM_STUDENTS; j++)
        printf("key[%2d] = %d\n", j, key[j]);

}

int hashft1(long students_id, int last) {
    long result;

    result = students_id % 1000;
    result = result % (last + 1);

    return result;
}

int hashft2(long students_id, int last) {
    long result;
    int div = 13;
    result = (students_id % div) + 1;

    return result;
}

int collision(long students_id, int last, int j) {
    long result;

    result = (hashft1(students_id, last) + j * hashft2(students_id, last) + j) % (last + 1);

    return result;
}

/////////////////////////////////////////////////////////////////////
// midterm problem 2
// implement hash function that is efficient for students_id
/////////////////////////////////////////////////////////////////////
int main()
{
    int last;
    long key[NUM_STUDENTS] = {0};

    last = NUM_STUDENTS - 1;

    buildhash(key, last);

    return 0;
}
