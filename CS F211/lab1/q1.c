#include<stdio.h>

struct Student{
    int id;
    char name[50];
    float marks[3];
    float avg;
};

int main(){
    struct Student students[50];
    int n;
    int topper = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter ID and Name of student %i ", i+1);
        scanf("%d %s", &students[i].id, &students[i].name);
        printf("Enter marks: ");
        scanf("%f %f %f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);

        float sum = 0;
        sum = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        students[i].avg = sum/3.0;
        if(students[i].avg > students[topper].avg){
            topper = i;
        }
    }

    printf("Merit List: \n");
    for(int i=0; i<n; i++){
        if(students[i].avg > 75){
            printf("%d %s (Avg: %.2f) \n", students[i].id, students[i].name, students[i].avg);
        }
    }

    printf("Topper: %s", students[topper].name);
    return 0;
}